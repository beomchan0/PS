#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];

queue<pair<int,int>> q;
bool visited[100][100];
int cnt=0;

bool InRange(int x, int y){
    return  x>=0&&x<n&&y>=0&&y<n;
}

bool CanGo(int x, int y){
    if(InRange(x,y)==false || grid[x][y]==1 || visited[x][y]==true){
        return false;
    }

    return true;
}

void Push(int x, int y){
    visited[x][y]=true;
    q.push(make_pair(x,y));
}

void BFS(){
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!q.empty()){
        pair<int, int> curr_pos=q.front();
        q.pop(); //pop 빼먹지 말자

        int x=curr_pos.first;
        int y=curr_pos.second;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(CanGo(nx,ny)){
                Push(nx,ny);
                cnt++;
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++){
        int r,c;
        cin >> r >> c;
        Push(r-1,c-1);
        cnt++;
    }
    BFS();
    cout << cnt;
    // Please write your code here.

    return 0;
}
