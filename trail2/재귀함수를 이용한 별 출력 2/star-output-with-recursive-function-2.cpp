#include <iostream>

using namespace std;

int n;

void f(int N){
    if(N==0) return;

    for(int i=0; i<N; i++){
        cout << "* ";
    }
    cout << "\n";

    f(N-1);

    for(int i=0; i<N; i++){
        cout << "* ";
    }
    cout << "\n";
}

int main() {
    cin >> n;

    f(n);
    // Please write your code here.

    return 0;
}