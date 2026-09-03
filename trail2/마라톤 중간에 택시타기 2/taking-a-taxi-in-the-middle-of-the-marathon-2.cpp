#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int x[100];
int y[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int minn=INT_MAX;
    int ans = 0;

    for(int i=1; i<n-1; i++){
        int dis=0;

        dis = (abs(x[i+1]-x[i-1]) + abs(y[i+1]-y[i-1])) - (abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]))-(abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]));


        minn = min(dis,minn);
    }

    for(int i=0; i<n-1; i++){
        ans = ans + abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]);
    }
    
    cout << ans + minn;
    

    // Please write your code here.

    return 0;
}