#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    int min1=0;
    int min2=0;

    min1 = 60*a + b;
    min2 = 60*c + d;

    cout << min2 - min1;

    // Please write your code here.

    return 0;
}