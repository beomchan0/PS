#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a,b;
    cin >> a >> b;
    int q=a/b;
    int r=a%b;

    cout << q << ".";
    for(int i=0; i<20; i++){
        r*=10;
        cout << r/b;
        r=r%b;
    }

    return 0;
}