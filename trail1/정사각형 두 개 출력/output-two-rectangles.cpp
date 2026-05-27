#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                cout << "*";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}