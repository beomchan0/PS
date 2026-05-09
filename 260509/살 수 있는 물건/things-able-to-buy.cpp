#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    if(N<1000){
        cout << "no\n";
    }else if(N<3000){
        cout << "mask\n";
    }else{
        cout << "book\n";
    }
    return 0;
}