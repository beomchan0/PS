#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    int arr[20];
    int cnt=0;
    int num=n;
    while(1){
        if(num<2){
            arr[cnt++] = num%2;
            break;
        }

        arr[cnt++] = num%2;
        num/=2;
    }

    for(int i=cnt-1; i>=0; i--){
        cout << arr[i];
    }

    // Please write your code here.

    return 0;
}