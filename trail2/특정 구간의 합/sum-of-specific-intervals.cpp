#include <iostream>

using namespace std;

int n, m;
int arr[101];
int queryA1[101];
int queryA2[101];

int f(int idx){
    int sum=0;
    for(int i=queryA1[idx]; i<=queryA2[idx]; i++){
        sum+=arr[i];
    }

    return sum;

}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> queryA1[i] >> queryA2[i];
    }

    for(int i=0; i<m; i++){
        cout << f(i) <<"\n";
    }



    // Please write your code here.

    return 0;
}