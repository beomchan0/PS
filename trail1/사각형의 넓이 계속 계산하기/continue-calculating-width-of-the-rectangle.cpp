#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    while(1){
        int a,b;
        char c;
        cin >> a >> b >> c;

        if(c=='C'){
            cout << a*b;
            break;
        }

        cout << a*b << "\n";
    }
    return 0;
}