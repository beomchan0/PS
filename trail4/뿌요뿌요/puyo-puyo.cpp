#include <iostream>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];
int cnt=0;
int bomb_cnt=0;
int max_cnt=0;

bool IsRange(int x, int y){
    return x>=0&&x<n&&y>=0&&y<n;
}

bool CanGo(int x, int y, int nx, int ny){
    if(IsRange(nx,ny)==false || grid[x][y]!=grid[nx][ny] || visited[nx][ny]==true){
        return false;
    }

    return true;
}
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void DFS(int x, int y){
    visited[x][y] = true;
    cnt++;

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(CanGo(x,y,nx,ny)){
            visited[nx][ny]=true;
            DFS(nx,ny);
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j]==false){
                cnt=0;
                DFS(i,j);

                if(cnt>=4) bomb_cnt++;

                if(cnt>max_cnt){
                    max_cnt=cnt;
                }

            }
        }
    }

    cout << bomb_cnt << " " << max_cnt;

    // Please write your code here.

    return 0;
}
