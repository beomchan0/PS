#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int A,B;
    cin >> A >> B;

    int sum=0;

    for(int i=A; i<=B; i++){
        sum += i;
    }

    cout << sum;
    return 0;
}