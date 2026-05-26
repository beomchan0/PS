#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int A,B;
    cin >> A >> B;

    int prod=1;

    for(int i=1; i<=B; i++){
        if(i%A==0){
            prod*=i;
        }
    }

    cout << prod;
    return 0;
}