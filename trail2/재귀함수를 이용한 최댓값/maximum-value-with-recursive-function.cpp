#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100];

int f(int N){
    if(N==1){
        return arr[0];
    }

    return max(arr[N-1], f(N-1));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << f(n);
    // Please write your code here.

    return 0;
}