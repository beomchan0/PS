#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10];

int lcm(int a, int b){
    int min_val=min(a,b);
    int max_val=max(a,b);

    for(int i=1; i<=min_val; i++){
        if((i*max_val)%min_val==0){
            return i*max_val;
        }
    }
}

int f(int idx){
    if(idx==0){
        return arr[0];
    }

    return lcm(arr[idx], f(idx-1));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << f(n-1);
    // Please write your code here.

    return 0;
}