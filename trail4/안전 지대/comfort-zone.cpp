#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, M;
int grid[50][50];
int k;
bool visited[50][50];
int max_safe=INT_MIN;

bool IsRange(int x, int y){
    return x>=0&&x<N&&y>=0&&y<M;
}

bool CanGo(int x, int y){
    if(IsRange(x,y)==false || grid[x][y]<=k || visited[x][y]==true){
        return false;
    }

    return true;
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void DFS(int x, int y){
    visited[x][y]=true;

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(CanGo(nx,ny)){
            visited[nx][ny]=true;
            DFS(nx,ny);
        }
    }
}

void init(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j]=false;
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    int max_k=0;

    for(k=1; k<=100; k++){
        init();
        int cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(CanGo(i,j)){
                    cnt++;
                    DFS(i,j);
                }
            }
        }
        if(max_safe<cnt){
            max_safe=cnt;
            max_k=k;
        }
    }

    cout << max_k << " " << max_safe;



    // Please write your code here.

    return 0;
}
