#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int A,B;

    cin >> A >> B;

    if(A<=B){
        for(int i=B; i>=A; i--){
            cout << i << " ";
        }
    }else{
        for(int i=A; i>=B; i--){
            cout << i << " ";
        }
    }
    return 0;
}