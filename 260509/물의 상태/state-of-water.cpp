#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    if(n<0){
        cout << "ice";
    }else if(n>=100){
        cout << "vapor";
    }else{
        cout << "water";
    }
    return 0;
}