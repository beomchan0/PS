#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int a[100][100];
bool visited[100][100];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

queue<pair<int,int>> q;

bool InRange(int x, int y){
    return x>=0&&x<n&&y>=0&&y<m;
}

bool CanGo(int x, int y){
    if(InRange(x,y)==false || a[x][y]==0 || visited[x][y]==true){
        return false;
    }

    return true;
}

void Push(int x, int y){
    visited[x][y] = true;
    q.push(make_pair(x,y));
}

void BFS(){
    while(!q.empty()){
        pair<int,int> curr_pos=q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(CanGo(nx,ny)){
                Push(nx,ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    Push(0,0);
    BFS();

    if(visited[n-1][m-1]==true){
        cout << 1;
    }else{
        cout << 0;
    }

    // Please write your code here.

    return 0;
}
