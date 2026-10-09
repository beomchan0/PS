#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm> // For std::min
#include <limits>    // For std::numeric_limits<int>::max()

// 전역 변수 정의
int n, m, f;
std::vector<std::vector<int>> space_grid;
std::vector<std::vector<std::vector<int>>> views; // views[face][r][c]
std::vector<std::tuple<int, int, int, int>> anomalies; // (r, c, d, v)

// 면(face) 인덱스 상수 정의 (가독성을 위해)
// views 리스트의 인덱스와 매핑됩니다.
const int EAST = 0;
const int WEST = 1;
const int SOUTH = 2;
const int NORTH = 3;
const int TOP = 4;

// 입력 처리 함수
void read_input() {
    std::cin >> n >> m >> f;

    // 미지의 공간 평면도 (N x N) 입력 받기
    space_grid.resize(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> space_grid[i][j];
        }
    }

    // 시간의 벽 단면도 입력 받기
    // views[0]: 동쪽 면, views[1]: 서쪽 면, views[2]: 남쪽 면, views[3]: 북쪽 면, views[4]: 윗면
    // 각 단면도는 M x M 크기
    views.resize(5, std::vector<std::vector<int>>(m, std::vector<int>(m)));
    for (int i = 0; i < 5; ++i) {
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < m; ++c) {
                std::cin >> views[i][r][c];
            }
        }
    }

    // 시간 이상 현상 정보 입력 받기 (r, c, d, v)
    anomalies.resize(f);
    for (int i = 0; i < f; ++i) {
        int r_i, c_i, d_i, v_i;
        std::cin >> r_i >> c_i >> d_i >> v_i;
        anomalies[i] = std::make_tuple(r_i, c_i, d_i, v_i);
    }
}

// find_exit_and_goal 함수
// 반환 값: (plane_exit_r, plane_exit_c, goal_face, goal_r, goal_c)
std::tuple<int, int, int, int, int> find_exit_and_goal(int wall_base_r, int wall_base_c) {
    int plane_exit_r = -1, plane_exit_c = -1; // 미지의 공간 평면도 상의 출구 좌표
    int goal_face = -1, goal_r = -1, goal_c = -1; // 시간의 벽 면에서의 상대 좌표

    // 북쪽 출구 탐색: 시간의 벽 위쪽 (wall_base_r - 1) 행
    if (wall_base_r > 0) {
        for (int c_off = 0; c_off < m; ++c_off) {
            if (space_grid[wall_base_r - 1][wall_base_c + c_off] == 0) {
                plane_exit_r = wall_base_r - 1;
                plane_exit_c = wall_base_c + c_off;
                // 북쪽 면에서 출구는 r=m-1 (가장 아래), c는 윗면에서 봤을 때의 c와 반대 방향으로 매핑됨 (m-1-c_off)
                goal_face = NORTH;
                goal_r = m - 1;
                goal_c = m - c_off - 1;
                return std::make_tuple(plane_exit_r, plane_exit_c, goal_face, goal_r, goal_c);
            }
        }
    }

    // 남쪽 출구 탐색: 시간의 벽 아래쪽 (wall_base_r + m) 행
    if (wall_base_r + m < n) {
        for (int c_off = 0; c_off < m; ++c_off) {
            if (space_grid[wall_base_r + m][wall_base_c + c_off] == 0) {
                plane_exit_r = wall_base_r + m;
                plane_exit_c = wall_base_c + c_off;
                // 남쪽 면에서 출구는 r=m-1 (가장 아래), c는 벽의 c_off와 동일하게 매핑
                goal_face = SOUTH;
                goal_r = m - 1;
                goal_c = c_off;
                return std::make_tuple(plane_exit_r, plane_exit_c, goal_face, goal_r, goal_c);
            }
        }
    }

    // 서쪽 출구 탐색: 시간의 벽 왼쪽 (wall_base_c - 1) 열
    if (wall_base_c > 0) {
        for (int r_off = 0; r_off < m; ++r_off) {
            if (space_grid[wall_base_r + r_off][wall_base_c - 1] == 0) {
                plane_exit_r = wall_base_r + r_off;
                plane_exit_c = wall_base_c - 1;
                // 서쪽 면에서 출구는 r=m-1 (가장 아래), c는 벽의 r_off와 동일하게 매핑
                goal_face = WEST;
                goal_r = m - 1;
                goal_c = r_off;
                return std::make_tuple(plane_exit_r, plane_exit_c, goal_face, goal_r, goal_c);
            }
        }
    }

    // 동쪽 출구 탐색: 시간의 벽 오른쪽 (wall_base_c + m) 열
    if (wall_base_c + m < n) {
        for (int r_off = 0; r_off < m; ++r_off) {
            if (space_grid[wall_base_r + r_off][wall_base_c + m] == 0) {
                plane_exit_r = wall_base_r + r_off;
                plane_exit_c = wall_base_c + m;
                // 동쪽 면에서 출구는 r=m-1 (가장 아래), c는 윗면에서 봤을 때의 r과 반대 방향으로 매핑됨 (m-1-r_off)
                goal_face = EAST;
                goal_r = m - 1;
                goal_c = m - r_off - 1;
                return std::make_tuple(plane_exit_r, plane_exit_c, goal_face, goal_r, goal_c);
            }
        }
    }

    // 모든 방향을 탐색했지만 출구를 찾지 못한 경우
    return std::make_tuple(-1, -1, -1, -1, -1);
}

// --- Phase 1: 시간의 벽 표면 탈출 --- //
// 반환 값: (time_to_exit_wall, plane_exit_r, plane_exit_c)
std::tuple<int, int, int> calc_escape_time_3d() {
    // 1-1. 시작점과 목표 지점 설정

    // 타임머신 시작 위치 찾기 (윗면에서 2로 표시된 곳)
    int start_face = -1, start_r = -1, start_c = -1;
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < m; ++c) {
            if (views[TOP][r][c] == 2) {
                start_face = TOP;
                start_r = r;
                start_c = c;
                views[TOP][r][c] = 0; // 시작점은 이제 빈 공간으로 간주하여 BFS 탐색에 방해되지 않도록 합니다.
                break;
            }
        }
        if (start_face != -1) break; // 시작점을 찾았으면 루프 종료
    }

    // 미지의 공간 평면도에서 시간의 벽(3)의 좌상단 위치 찾기
    int wall_base_r = -1, wall_base_c = -1;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (space_grid[r][c] == 3) {
                wall_base_r = r;
                wall_base_c = c;
                goto found_wall_base; // 이중 루프 탈출
            }
        }
    }
found_wall_base:;

    // 시간의 벽에서 미지의 공간으로 이어지는 출구 (plane_exit)와
    // 그 출구에 해당하는 시간의 벽 옆면의 상대 좌표 (goal_face, goal_r, goal_c) 찾기
    auto [plane_exit_r, plane_exit_c, goal_face, goal_r, goal_c] = find_exit_and_goal(wall_base_r, wall_base_c);

    // 출구를 찾지 못했거나, 찾은 출구가 시간의 벽 단면도 상에서 장애물인 경우 탈출 불가능
    if (goal_face == -1 || views[goal_face][goal_r][goal_c] == 1) {
        return std::make_tuple(-1, -1, -1);
    }

    // 1-2. 표면 이동 BFS
    // 큐: (현재 시간, 현재 면, 현재 면 내의 행, 현재 면 내의 열)
    std::queue<std::tuple<int, int, int, int>> q_surf;
    q_surf.push(std::make_tuple(0, start_face, start_r, start_c));

    // 방문 기록: (면, 행, 열) 튜플을 저장하는 3차원 배열. 중복 탐색 방지.
    std::vector<std::vector<std::vector<bool>>> visited_surf(
        5, std::vector<std::vector<bool>>(m, std::vector<bool>(m, false))
    );
    visited_surf[start_face][start_r][start_c] = true;
    int time_to_exit_wall = -1; // 시간의 벽을 탈출하는 데 걸리는 시간

    int dr[] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
    int dc[] = {0, 0, -1, 1};

    while (!q_surf.empty()) {
        auto [time, face, r, c] = q_surf.front();
        q_surf.pop();

        // 목표 지점(시간의 벽 출구)에 도달했으면 시간 기록 후 BFS 종료
        // +1을 하는 이유는, 해당 칸에 도달하는 데 걸린 시간(time)에 1턴을 더하여
        // 다음 턴에 미지의 공간 바닥으로 내려갈 수 있음을 의미합니다.
        if (face == goal_face && r == goal_r && c == goal_c) {
            time_to_exit_wall = time + 1;
            break;
        }

        // 1. 같은 면 내에서 이동 (상하좌우 4방향)
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            // 면 내 유효 범위 확인 (0 <= nr, nc < M)
            if (nr >= 0 && nr < m && nc >= 0 && nc < m) {
                // 이동할 칸이 빈 공간(0)이고 아직 방문하지 않았다면
                if (views[face][nr][nc] == 0 && !visited_surf[face][nr][nc]) {
                    visited_surf[face][nr][nc] = true; // 방문 기록
                    q_surf.push(std::make_tuple(time + 1, face, nr, nc)); // 큐에 추가 (시간 1 증가)
                }
            }
        }

        // 2. 다른 면으로 이동 (면의 가장자리에서 인접한 면으로)
        // (다음 면, 다음 면 내의 행, 다음 면 내의 열)
        std::vector<std::tuple<int, int, int>> transitions;

        // 윗면(TOP)에서 다른 면으로 이동 규칙
        if (face == TOP) {
            if (r == 0)      transitions.emplace_back(NORTH, 0, m - c - 1); // 윗면의 0행(북쪽 가장자리) -> 북쪽 면의 0행 (열은 반전)
            if (r == m - 1)  transitions.emplace_back(SOUTH, 0, c);       // 윗면의 m-1행(남쪽 가장자리) -> 남쪽 면의 0행 (열은 그대로)
            if (c == 0)      transitions.emplace_back(WEST, 0, r);        // 윗면의 0열(서쪽 가장자리) -> 서쪽 면의 0행 (행은 그대로)
            if (c == m - 1)  transitions.emplace_back(EAST, 0, m - r - 1); // 윗면의 m-1열(동쪽 가장자리) -> 동쪽 면의 0행 (행은 반전)
        }
        // 북쪽 면(NORTH)에서 다른 면으로 이동 규칙
        else if (face == NORTH) {
            if (r == 0)      transitions.emplace_back(TOP, 0, m - c - 1); // 북쪽 면의 0행 -> 윗면의 0행 (열은 반전)
            if (c == m - 1)  transitions.emplace_back(WEST, r, 0);        // 북쪽 면의 m-1열 -> 서쪽 면의 r행 (0열)
            if (c == 0)      transitions.emplace_back(EAST, r, m - 1);    // 북쪽 면의 0열 -> 동쪽 면의 r행 (m-1열)
        }
        // 남쪽 면(SOUTH)에서 다른 면으로 이동 규칙
        else if (face == SOUTH) {
            if (r == 0)      transitions.emplace_back(TOP, m - 1, c);     // 남쪽 면의 0행 -> 윗면의 m-1행 (열은 그대로)
            if (c == 0)      transitions.emplace_back(WEST, r, m - 1);    // 남쪽 면의 0열 -> 서쪽 면의 r행 (m-1열)
            if (c == m - 1)  transitions.emplace_back(EAST, r, 0);        // 남쪽 면의 m-1열 -> 동쪽 면의 r행 (0열)
        }
        // 서쪽 면(WEST)에서 다른 면으로 이동 규칙
        else if (face == WEST) {
            if (r == 0)      transitions.emplace_back(TOP, c, 0);         // 서쪽 면의 0행 -> 윗면의 c열 (0행)
            if (c == 0)      transitions.emplace_back(NORTH, r, m - 1);   // 서쪽 면의 0열 -> 북쪽 면의 r행 (m-1열)
            if (c == m - 1)  transitions.emplace_back(SOUTH, r, 0);       // 서쪽 면의 m-1열 -> 남쪽 면의 r행 (0열)
        }
        // 동쪽 면(EAST)에서 다른 면으로 이동 규칙
        else if (face == EAST) {
            if (r == 0)      transitions.emplace_back(TOP, m - c - 1, m - 1); // 동쪽 면의 0행 -> 윗면의 m-1열 (행은 반전)
            if (c == m - 1)  transitions.emplace_back(NORTH, r, 0);         // 동쪽 면의 m-1열 -> 북쪽 면의 r행 (0열)
            if (c == 0)      transitions.emplace_back(SOUTH, r, m - 1);     // 동쪽 면의 0열 -> 남쪽 면의 r행 (m-1열)
        }

        for (const auto& transition : transitions) {
            int next_face, next_r, next_c;
            std::tie(next_face, next_r, next_c) = transition;

            // 이동할 칸이 빈 공간(0)이고 아직 방문하지 않았다면
            if (views[next_face][next_r][next_c] == 0 && !visited_surf[next_face][next_r][next_c]) {
                visited_surf[next_face][next_r][next_c] = true; // 방문 기록
                q_surf.push(std::make_tuple(time + 1, next_face, next_r, next_c)); // 큐에 추가 (시간 1 증가)
            }
        }
    }

    // 시간의 벽을 탈출하는데 걸린 시간 반환
    return std::make_tuple(time_to_exit_wall, plane_exit_r, plane_exit_c);
}

// --- Phase 2: 미지의 공간 횡단 --- //
int calc_dest_time_2d(int time_to_exit_wall, int plane_exit_r, int plane_exit_c) {
    // Phase 1에서 탈출에 실패했다면, Phase 2도 불가능
    if (time_to_exit_wall == -1) {
        return -1;
    }

    // 미지의 공간 평면도에서 최종 탈출구(4) 위치 찾기
    int escape_r = -1, escape_c = -1;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (space_grid[r][c] == 4) {
                escape_r = r;
                escape_c = c;
                goto found_escape_goal; // 이중 루프 탈출
            }
        }
    }
found_escape_goal:;

    // 시간 이상 현상에 의해 각 칸이 언제부터 막히는지 기록하는 배열
    // anomaly_blocks[r][c] = (r,c) 칸이 막히는 가장 빠른 시간
    // 초기값은 무한대로 설정하여, 막히지 않는 칸은 계속 무한대 값을 가집니다.
    std::vector<std::vector<int>> anomaly_blocks(n, std::vector<int>(n, std::numeric_limits<int>::max()));

    // 시간 이상 현상 확산 방향 (동, 서, 남, 북)
    // 문제에서 주어진 방향: 동(0), 서(1), 남(2), 북(3)
    int anomaly_dr[] = {0, 0, 1, -1}; // E, W, S, N
    int anomaly_dc[] = {1, -1, 0, 0};

    // 각 시간 이상 현상에 대해 확산 경로 및 차단 시간 전처리
    for (const auto& anomaly_info : anomalies) {
        int r_i, c_i, d_i, v_i;
        std::tie(r_i, c_i, d_i, v_i) = anomaly_info;

        // 시작 위치가 탈출구(4)가 아닌 경우에만 시간 이상 현상으로 막힐 수 있음
        if (space_grid[r_i][c_i] != 4) { 
            anomaly_blocks[r_i][c_i] = std::min(anomaly_blocks[r_i][c_i], 0);
        }
        
        int time_step = 0;
        int current_r = r_i;
        int current_c = c_i;

        while (true) {
            current_r += anomaly_dr[d_i];
            current_c += anomaly_dc[d_i];
            time_step += v_i; // 다음 확산 시간

            // 격자 범위를 벗어나거나, 장애물(1)이거나, 시간의 벽(3)이거나, 탈출구(4)인 경우 확산 중단
            if (!(current_r >= 0 && current_r < n && current_c >= 0 && current_c < n) || 
                space_grid[current_r][current_c] == 1 || 
                space_grid[current_r][current_c] == 3 || 
                space_grid[current_r][current_c] == 4) {
                break;
            }
            // 해당 칸이 막히는 가장 빠른 시간을 갱신
            anomaly_blocks[current_r][current_c] = std::min(anomaly_blocks[current_r][current_c], time_step);
        }
    }

    // BFS 큐: (현재 시간, 현재 행, 현재 열)
    // 시작 시간은 시간의 벽을 탈출하는 데 걸린 시간입니다.
    std::queue<std::tuple<int, int, int>> q_2d;
    q_2d.push(std::make_tuple(time_to_exit_wall, plane_exit_r, plane_exit_c));

    // 같은 칸이라도 더 빠른 시간에 도달하는 경로가 있다면 갱신하기 위함입니다.
    // visited_2d[r][c]는 (r,c)에 도달하는 최소 시간을 저장합니다.
    std::vector<std::vector<int>> visited_2d(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    visited_2d[plane_exit_r][plane_exit_c] = time_to_exit_wall;

    // 상하좌우 4방향 이동
    int dr_2d[] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
    int dc_2d[] = {0, 0, -1, 1};

    while (!q_2d.empty()) {
        auto [time, cr, cc] = q_2d.front();
        q_2d.pop();

        // 최종 탈출구에 도달했으면 현재 시간 반환
        if (cr == escape_r && cc == escape_c) {
            return time;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = cr + dr_2d[i];
            int nc = cc + dc_2d[i];
            int next_time = time + 1; // 다음 칸으로 이동하는 데 걸리는 시간

            // 이동 조건 확인:
            // 1. 격자 범위 내에 있는지
            // 2. 장애물(1)이나 시간의 벽(3)이 아닌지 (시간의 벽은 2D 평면에서 장애물로 간주)
            // 3. 다음 시간에 해당 칸이 시간 이상 현상으로 막히지 않는지 (next_time < anomaly_blocks[nr][nc])
            // 4. 이미 방문했더라도 현재 경로가 더 빠른지 (next_time < visited_2d[nr][nc])
            if ((nr >= 0 && nr < n && nc >= 0 && nc < n) &&
                space_grid[nr][nc] != 1 && space_grid[nr][nc] != 3 &&
                next_time < anomaly_blocks[nr][nc] &&
                next_time < visited_2d[nr][nc]) {
                // 이동 가능하면 방문 기록 갱신 및 큐에 추가
                visited_2d[nr][nc] = next_time;
                q_2d.push(std::make_tuple(next_time, nr, nc));
            }
        }
    }

    // 모든 경로를 탐색했지만 탈출구에 도달하지 못했다면 -1 반환
    return -1;
}

// --- 메인 실행 --- //
int main() {
    // C++ 표준 스트림 동기화 해제 및 tie 해제 (입출력 속도 향상)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    read_input();
    // Phase 1: 시간의 벽 표면 탈출 시간 계산
    auto [time_to_exit_wall, plane_exit_r, plane_exit_c] = calc_escape_time_3d();
    // Phase 2: 미지의 공간 횡단 시간 계산
    int time_to_goal = calc_dest_time_2d(time_to_exit_wall, plane_exit_r, plane_exit_c);
    std::cout << time_to_goal << std::endl;

    return 0;
}
