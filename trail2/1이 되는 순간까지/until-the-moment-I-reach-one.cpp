#include <iostream>

using namespace std;

int N;

int f(int n){
    if(n==1){
        return 0;
    }

    if(n%2==0){
        return 1+f(n/2);
    }else{
        return 1+f(n/3);
    }
}

int main() {
    cin >> N;

    cout << f(N);

    // Please write your code here.

    return 0;
}