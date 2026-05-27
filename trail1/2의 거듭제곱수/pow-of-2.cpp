#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    int cnt=0;

    while(N!=1){
        N/=2;
        cnt++;
    }

    cout << cnt;
    return 0;
}