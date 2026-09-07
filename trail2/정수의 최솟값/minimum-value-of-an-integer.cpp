#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

int f(int a, int b, int c){
    int min_val=min(a,b);
    min_val=min(min_val,c);

    return min_val;
}

int main() {
    cin >> a >> b >> c;

    cout << f(a,b,c);
    // Please write your code here.

    return 0;
}