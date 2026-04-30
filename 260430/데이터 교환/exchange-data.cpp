#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a,b,c;
    int temp;
    a=5;
    b=6;
    c=7;
    temp = a;
    a = c;
    c = b;
    b = temp;

    cout << a << "\n" << b << "\n" << c;

    return 0;
}