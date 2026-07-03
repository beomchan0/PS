#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    for(int i=N; i>=1; i--){
        for(int j=0; j<i; j++){
            cout << "* "; 
        }
        cout << "\n";
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<i; j++){
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}