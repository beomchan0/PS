#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    int min1=10*1440 + 11*60 + 11;
    int min2=(a-1)*1440 + b*60 + c;

    if(min1>min2) cout << -1;
    else cout << min2-min1;

    // Please write your code here.

    return 0;
}