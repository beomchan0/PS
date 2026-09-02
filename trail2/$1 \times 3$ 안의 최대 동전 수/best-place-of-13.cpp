#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> grid[i][j];

    int ans=0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N-2; j++){
            int cnt=0;
            cnt = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            ans = max(ans,cnt);
            if(ans==3) break;
        }
        if(ans==3) break;
    }

    cout << ans;

    // Please write your code here.

    return 0;
}