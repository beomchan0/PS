#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100];

int dx[2] = {1,0};
int dy[2] = {0,1};

bool IsRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

bool CanGo(int x, int y){
    if(IsRange(x,y)!=true || grid[x][y]==0 || visited[x][y]==true){
        return false;
    }


    return true;
}

void DFS(int x, int y){
    visited[x][y] = true;

    for(int i=0; i<2; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(CanGo(nx,ny)){
            visited[nx][ny]=true;
            DFS(nx,ny);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    DFS(0,0);

    if(visited[n-1][m-1]==true){
        cout << 1;
    }else{
        cout << 0;
    }

    // Please write your code here.

    return 0;
}
