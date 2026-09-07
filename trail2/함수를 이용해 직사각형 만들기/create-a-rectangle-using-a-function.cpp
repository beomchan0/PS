#include <iostream>

using namespace std;

void printnm(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "1";
        }
        cout << "\n";
    }
}

int n, m;

int main() {
    cin >> n >> m;

    printnm(n,m);
    // Please write your code here.

    return 0;
}