#include <iostream>

using namespace std;

int a, b;

void f(int &n1, int &n2){
    if(n1>n2){
        n1 *=2;
        n2 +=10;
    }else{
        n2 *=2;
        n1 +=10;
    }
}

int main() {
    cin >> a >> b;

    f(a, b);

    cout << a << " " << b;

    // Please write your code here.

    return 0;
}