#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

void printgcd(int n, int m){
    int min_val=min(n,m);

    for(int i=min_val; i>0; i--){
        if(n%i==0&&m%i==0){
            cout << i;
            break;
        }
    }
}

int main() {
    cin >> n >> m;

    printgcd(n,m);



    // Please write your code here.

    return 0;
}