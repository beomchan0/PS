#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a;
    cin >> a;
    if(a%2==0){
        a/=2;
    }

    if(a%2==1){
        a = (a+1)/2;
    }

    cout << a;
    return 0;
}