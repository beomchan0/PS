#include <iostream>

using namespace std;

int a, b;

void f(int *p1, int *p2){
    if(*p1>*p2){
        *p1 *=2;
        *p2 +=10;
    }else{
        *p2 *=2;
        *p1 +=10;
    }
}

int main() {
    cin >> a >> b;

    f(&a, &b);

    cout << a << " " << b;

    // Please write your code here.

    return 0;
}