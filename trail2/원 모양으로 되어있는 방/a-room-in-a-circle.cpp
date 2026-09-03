#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int a[1003];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_val=INT_MAX;

    for(int i=0; i<n; i++){
        //i번째 방을 선택함.
        int dis=0;
        for(int j=0; j<n; j++){
            dis+=a[(i+j)%n]*j;
        }

        min_val = min(min_val,dis);
    }

    cout << min_val;



    // Please write your code here.

    return 0;
}