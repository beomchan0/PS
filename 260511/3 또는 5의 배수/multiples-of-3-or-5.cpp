#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a;
    cin >> a;
    if(a%3==0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    if(a%5==0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}