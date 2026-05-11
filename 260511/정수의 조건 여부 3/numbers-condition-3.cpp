#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a;
    cin >> a;
    if(a%13==0||a%19==0){
        cout << "True\n";
    }else{
        cout << "False\n";
    }
    return 0;
}