#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    if(n<500){
        cout << "no\n";
    }else if(n<1000){
        cout << "pen\n";
    }else if(n<3000){
        cout << "mask\n";
    }else{
        cout << "book\n";
    }
    return 0;
}