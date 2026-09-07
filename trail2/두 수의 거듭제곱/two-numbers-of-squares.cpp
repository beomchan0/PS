#include <iostream>

using namespace std;

int a, b;

void f(int n, int m){
    int ans=1;
    for(int i=0; i<m; i++){
        ans*=a;
    }
    cout << ans;
}

int main() {
    cin >> a >> b;

    f(a,b);

    // Please write your code here.

    return 0;
}