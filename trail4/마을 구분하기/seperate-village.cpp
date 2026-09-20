#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];
int num_man[625];
int cnt_town=0;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool visited[25][25];

bool IsRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

bool CanGo(int x, int y){
    if(IsRange(x,y)==false || grid[x][y]==0 || visited[x][y]==true){
        return false;
    }
    return true;
}

void DFS(int x, int y, int& cnt){
    visited[x][y] = true;
    cnt++;

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(CanGo(nx,ny)){
            visited[nx][ny]=true;
            DFS(nx,ny,cnt);
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
            if(CanGo(i,j)){
                
                int cnt=0;
                DFS(i,j,cnt);
                num_man[cnt_town++]=cnt;
            }
        }
    }

    sort(num_man, num_man+cnt_town);

    cout << cnt_town << "\n";
    for(int i=0; i<cnt_town; i++){
        cout << num_man[i] << "\n";
    }



    // Please write your code here.

    return 0;
}
