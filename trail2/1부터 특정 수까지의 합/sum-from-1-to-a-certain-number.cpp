#include <iostream>

using namespace std;

int N;

int f(int n){
    int sum=0;
    for(int i=1; i<=n; i++){
        sum+=i;
    }

    return sum/10;
}

int main() {
    cin >> N;

    cout << f(N);
    // Please write your code here.

    return 0;
}