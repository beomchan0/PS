#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int A,B;
    cin >> A >> B;
    int i=A;
    while(i<=B){
        cout << i << " ";
        if(i%2==1){
            i*=2;
        }else{
            i+=3;
        }
    }
    return 0;
}