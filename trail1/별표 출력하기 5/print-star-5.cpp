#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    for(int i=N; i>0; i--){
        for(int j=0; j<i; j++){
            for(int k=0; k<i; k++){
                cout << "*";
            }
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}