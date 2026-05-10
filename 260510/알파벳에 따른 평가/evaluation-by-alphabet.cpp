#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    char c;
    cin >> c;
    if(c=='S'){
        cout << "Superior\n";
    }else if(c=='A'){
        cout << "Excellent\n";
    }else if(c=='B'){
        cout << "Good\n";
    }else if(c=='C'){
        cout << "Usually\n";
    }else if(c=='D'){
        cout << "Effort\n";
    }else{
        cout << "Failure\n";
    }
    return 0;
}