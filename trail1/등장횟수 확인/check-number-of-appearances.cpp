#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int cnt=0;
    for(int i=0; i<5; i++){
        int a;
        cin >> a;
        if(a%2==0){
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}