#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a,b;
    cin >> a >> b;

    if(a>=90){
        if(b<90){
            cout << "0";
        }else if(b<95){
            cout << "50000";
        }else if(b<=100){
            cout << "100000";
        }
    }else{
        cout << "0";
    }

    return 0;
}