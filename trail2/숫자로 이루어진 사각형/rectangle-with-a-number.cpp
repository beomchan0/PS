#include <iostream>

using namespace std;

int N;

void makes(int n){
    int a=1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=n; j++){
            if(a==10){
                a=1;
            }
            cout << a++ << " ";
        }
        cout << "\n";
    }
}


int main() {
    cin >> N;

    makes(N);

    // Please write your code here.

    return 0;
}