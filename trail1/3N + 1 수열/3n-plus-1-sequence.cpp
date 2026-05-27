#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    int cnt=0;

    while(1){
        if(N==1){
            break;
        }

        if(N%2==0){
            N/=2;
        }else{
            N= N*3+1;
        }

        cnt++;
    }


    cout << cnt;
    return 0;
}