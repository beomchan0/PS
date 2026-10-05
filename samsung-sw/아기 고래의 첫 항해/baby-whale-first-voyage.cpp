#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int grid[51][51]; // 0:바다, 1:암초, 2:아기 고래가 지나간곳.
int n;
int start_r, start_c;
int start_d;
int cur_d; // 방향을 '상 -> 우 -> 하 -> 좌' 로 재정의 
int make_d[5]={0,0,2,3,1};
int cur_r,cur_c;
int goal_r,goal_c;
int visited[51][51];
queue<pair<int,int>> q;
int dist[51][51];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool InRange(int r, int c){
    return (r>=1&&r<=n&&c>=1&&c<=n);
}

bool CanGo1(int nx, int ny){
    //맨 처음 grid 업데이트에 사용하는 CanGo
    if(InRange(nx,ny)&&grid[nx][ny]!=1&&visited[nx][ny]==0){
        return true;
    }

    return false;
}

bool CanGo2(int nx, int ny, int c_num){

    if(InRange(nx,ny)&&(grid[nx][ny]==2||grid[nx][ny]==0)&&visited[nx][ny]==0&&c_num==2){
        return true;
    }

    return false;
}

bool CanGo3(int nx, int ny){

    if(InRange(nx,ny)&&grid[nx][ny]==2&&visited[nx][ny]==0){
        return true;
    }

    return false;
}


void init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visited[i][j]=0;
            dist[i][j]=0;
        }
    }
}

void Push(int x, int y){
    visited[x][y]=1;
    q.push(make_pair(x,y));
}

void BFS1(){
    //처음에 사용하는 BFS.
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();

        int x=cur.first;
        int y=cur.second;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo1(nx,ny)){
                Push(nx,ny);
            }
        }
    }
}

void BFS2(){
    //나중에 사용하는 BFS.
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();

        int x=cur.first;
        int y=cur.second;
        int c_num=grid[x][y];
        int cur_dist=dist[x][y];
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(CanGo2(nx,ny,c_num)){
                dist[nx][ny]=cur_dist+1;
                Push(nx,ny);
            }
        }
    }
}

void BFS3(){
    //경로 탐색시 사용하는 BFS.
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();

        int x=cur.first;
        int y=cur.second;
        int cur_dist=dist[x][y];
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo3(nx,ny)){
                dist[nx][ny]=cur_dist+1;
                Push(nx,ny);
            }
        }
    }
}


bool is_done(){
    //이거 어떻게 체크하지..
    //처음에 BFS 수행해서 못가는 칸은 그냥 암초처리하는 방법.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]==0){
                return false;
            }
        }
    }

    return true;
}

bool can_go_near(){
    //현재 위치에서 인접탐험 가능한지 체크
    for(int i=0; i<4; i++){
        int nx=cur_r+dx[i];
        int ny=cur_c+dy[i];

        if(InRange(nx,ny)&&grid[nx][ny]==0){
            return true;
        }
    }

    return false;
}

void go_near(){
    //반드시 가능한 경우만 주어짐.
    //인접 탐험 진행 후 grid 업데이트 하고, 위치 출력.

    if(InRange(cur_r+dx[cur_d],cur_c+dy[cur_d])&&grid[cur_r+dx[cur_d]][cur_c+dy[cur_d]]==0){
        cur_r=cur_r+dx[cur_d];
        cur_c=cur_c+dy[cur_d];
        grid[cur_r][cur_c]=2;
        cout << cur_r << " " << cur_c << "\n";
    }else if(InRange(cur_r+dx[(cur_d+3)%4],cur_c+dy[(cur_d+3)%4])&&grid[cur_r+dx[(cur_d+3)%4]][cur_c+dy[(cur_d+3)%4]]==0){
        cur_d=(cur_d+3)%4;
        cur_r=cur_r+dx[cur_d];
        cur_c=cur_c+dy[cur_d];
        grid[cur_r][cur_c]=2;
        cout << cur_r << " " << cur_c << "\n";
    }else if(InRange(cur_r+dx[(cur_d+1)%4],cur_c+dy[(cur_d+1)%4])&&grid[cur_r+dx[(cur_d+1)%4]][cur_c+dy[(cur_d+1)%4]]==0){
        cur_d=(cur_d+1)%4;
        cur_r=cur_r+dx[cur_d];
        cur_c=cur_c+dy[cur_d];
        grid[cur_r][cur_c]=2;
        cout << cur_r << " " << cur_c << "\n";
    }else if(InRange(cur_r+dx[(cur_d+2)%4],cur_c+dy[(cur_d+2)%4])&&grid[cur_r+dx[(cur_d+2)%4]][cur_c+dy[(cur_d+2)%4]]==0){
        cur_d=(cur_d+2)%4;
        cur_r=cur_r+dx[cur_d];
        cur_c=cur_c+dy[cur_d];
        grid[cur_r][cur_c]=2;
        cout << cur_r << " " << cur_c << "\n";
    }
}



void find_goal(){
    //goal_r, goal_c 찾기.
    init();
    dist[cur_r][cur_c]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]==1){
                dist[i][j]=10000; // 갈 수 없는 곳의 거리는 매우 크게 설정
            }
        }
    }

    Push(cur_r,cur_c);
    BFS2(); // dist에 현재 위치에서 갈 수 있는 모든지점까지 거리가 기록되어 있음.

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j]==0){
                dist[i][j]=10000; // 못간 곳의 거리는 매우 크게 설정
            }
        }
    }

    int min=10000;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]==0&&dist[i][j]<min){
                min=dist[i][j];
                goal_r=i;
                goal_c=j;
            }
        }
    }
    // 목표 지점 r c 탐색 완료.

}

void move_goal(int r1, int c1, int d, int r2, int c2){
    init();
    dist[r2][c2]=0;
    grid[r2][c2]=2;
    
    //경로 찾고 업데이트 하는 과정.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]==1||grid[i][j]==0){
                dist[i][j]=10000; // 갈 수 없는 곳의 거리는 매우 크게 설정
            }
        }
    }
    
    Push(r2,c2);
    BFS3(); 

    for(int k=0; k<dist[r1][c1];k++){
        int arr[4]={3,2,1,0}; //좌 하 우 상의 우선 순위.

        for(int i=0; i<4; i++){
            int nx=cur_r+dx[arr[i]];
            int ny=cur_c+dy[arr[i]];
            if(InRange(nx,ny)&&(k==dist[r1][c1]-1||grid[nx][ny]==2)&&dist[nx][ny]+1==dist[cur_r][cur_c]){
                cur_r=nx;
                cur_c=ny;
                cur_d=arr[i];
                break;
            }
        }
    }

    cout << cur_r << " " << cur_c << "\n";
    
}

void simulate(){
    if(can_go_near()){
        //인접 탐험 가능하다면 우선 순위따라 진행.
        go_near();
    }else{
        find_goal(); // 가장 가까운 바다 찾기.
        move_goal(cur_r, cur_c, cur_d, goal_r, goal_c); // 현재 위치에서 목표지점 까지 경로 출력.
    }
}

void make_grid(){
    //BFS 처음에 수행해서 방문 안된곳은 절때 못가는 곳이니깐 암초 처리.
    Push(start_r,start_c);
    BFS1();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j]==0){
                grid[i][j]=1;
                //초기 BFS1 진행 후 갈수 없는 곳은 암초 또는 그냥 탐색 불가 지점 이므로 다 암초로 처리해도 됨.
            }
        }
    }
}

int main() {
    // Please write your code here.

    cin >> n >> start_r >> start_c >> start_d;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> grid[i][j];
        }
    }

    cur_d=make_d[start_d];
    cur_r=start_r;
    cur_c=start_c;

    grid[cur_r][cur_c]=2;
    cout << cur_r << " " << cur_c << "\n";

    make_grid();

    while(!is_done()){
        simulate();
    }


    return 0;
}