#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int h,w;
    cin >> h >> w;
    int b;
    b=(10000*w) / (h*h);
    cout << b << "\n";
    if(b>=25){
        cout << "Obesity";
    }
    return 0;
}