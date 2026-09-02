#include <iostream>

using namespace std;

int R, C;
char grid[15][15];

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int cnt=0;

    for(int i=1; i<R-2; i++){
        for(int j=1; j<C-2; j++){
            for(int k=i+1; k<R-1; k++){
                for(int t=j+1; t<C-1; t++){
                    if(grid[0][0]!=grid[i][j]&&grid[i][j]!=grid[k][t]&&grid[k][t]!=grid[R-1][C-1]){
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt;

    // Please write your code here.

    return 0;
}