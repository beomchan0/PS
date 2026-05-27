#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        int a;
        a=2*i-1;
        for(int j=0; j<a; j++){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}