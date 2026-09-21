#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r, c;
bool visited[100][100];
queue<pair<int,int>> q;
int max_v=0;
int mx=100;
int my=100;

bool InRange(int x, int y){
    return x>=0&&x<n&&y>=0&&y<n;
}

bool CanGo(int x, int y, int nx, int ny){
    if(InRange(nx,ny)==false || grid[x][y] <= grid[nx][ny] || visited[nx][ny]==true){
        return false;
    }

    return true;
}

void Push(int x, int y){
    q.push(make_pair(x,y));
    visited[x][y]=true;
}

void init(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j]=false;
        }
    }
    max_v=0;
}
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

void BFS(int bx, int by){
    while(!q.empty()){
        pair<int,int> curr_pos=q.front();
        q.pop();
        int x=curr_pos.first;
        int y=curr_pos.second;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo(bx,by,nx,ny)){
                Push(nx,ny);
                if(max_v<grid[nx][ny]){
                    max_v=grid[nx][ny];
                    mx=nx;
                    my=ny;
                }else if(max_v==grid[nx][ny]){
                    if(nx==mx){
                        if(ny<my){
                            my=ny;
                        }
                    }else if(nx<mx){
                        mx=nx;
                        my=ny;
                    }
                }
            }
        }
    }
}

void search(int x, int y){
    
    for(int i=0; i<k; i++){
        init();
        Push(x,y);
        BFS(x,y);
        if(max_v==0){
            break;
        }else{
            x=mx;
            y=my;
        }
    }

    cout << x+1 << " " << y+1;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    search(r-1,c-1);

    // Please write your code here.

    return 0;
}
