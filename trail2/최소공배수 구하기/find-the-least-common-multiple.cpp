#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

void printlcm(int n, int m){
    int max_val=max(n,m);

    for(int i=max_val; i<=n*m; i+=max_val){
        if(i%n==0&&i%m==0){
            cout << i;
            break;
        }
    }
}

int main() {
    cin >> n >> m;

    printlcm(n,m);

    // Please write your code here.

    return 0;
}