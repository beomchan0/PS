#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    double r,l;
    cin >> r >> l;
    if(r>=1&&l>=1){
        cout << "High";
    }else if(r>=0.5&&l>=0.5){
        cout << "Middle";
    }else{
        cout << "Low";
    }
    return 0;
}