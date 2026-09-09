#include <iostream>

using namespace std;

int N;

void f(int n){
    if(n==0){
        return;
    }

    f(n-1);
    cout << "HelloWorld\n";
}

int main() {
    cin >> N;

    f(N);

    // Please write your code here.

    return 0;
}