#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    while(1){
        int a;
        cin >> a;

        if(a==25){
            cout << "Good";
            break;
        }

        if(a>25){
            cout << "Lower\n";
        }else{
            cout << "Higher\n";
        }
    }
    return 0;
}