#include <iostream>

using namespace std;

int N;

int f(int n){
    if(n/10==0) return n*n;

    return (n%10)*(n%10) + f(n/10);
}

int main() {
    cin >> N;
    cout << f(N);

    // Please write your code here.

    return 0;
}