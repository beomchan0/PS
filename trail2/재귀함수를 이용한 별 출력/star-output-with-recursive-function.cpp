#include <iostream>

using namespace std;

int n;

void f(int n){
    if(n==0){
        return;
    }
    f(n-1);
    for(int i=0; i<n; i++){
        cout << "*";
    }
    cout << "\n";
}

int main() {
    cin >> n;
    f(n);

    // Please write your code here.

    return 0;
}