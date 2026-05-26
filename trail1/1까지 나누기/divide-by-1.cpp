#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    int i=1;
    int cnt=0;
    while(1){
        N/=i;
        cnt++;

        if(N<=1){
            break;
        }
        i++;
    }

    cout << cnt;
    return 0;
}