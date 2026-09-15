#include <iostream>

using namespace std;

int N, B;
int arr[10];

int main() {
    cin >> N >> B;

    int cnt=0;

    while(1){
        if(N<B){
            arr[cnt++] = N;
            break;
        }

        arr[cnt++] = N%B;
        N/=B;
    }

    for(int i=cnt-1; i>=0; i--){
        cout << arr[i];
    }
    // Please write your code here.

    return 0;
}