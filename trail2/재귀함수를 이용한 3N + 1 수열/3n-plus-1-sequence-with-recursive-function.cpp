#include <iostream>

using namespace std;

int n;

int f(int N){
    if(N==1){
        return 0;
    }

    if(N%2==0){
        return 1+f(N/2);
    }else{
        return 1+f(N*3+1);
    }
}

int main() {
    cin >> n;

    cout << f(n);
    // Please write your code here.

    return 0;
}