#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int b,a;
    cin >> b >> a;
    for(int i=b; i>=a; i-=2){
        cout << i << " ";
    }
    return 0;
}