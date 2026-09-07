#include <iostream>

using namespace std;

int a, b;

void f(int *n1, int *n2){
    if(*n1>*n2){
        *n1+=25;
        *n2*=2;
    }else{
        *n2+=25;
        *n1*=2;
    }
}

int main() {
    cin >> a >> b;

    f(&a, &b);
    cout << a << " " << b;
    // Please write your code here.

    return 0;
}