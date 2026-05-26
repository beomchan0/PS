#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int cnt=0;
    for(int i=0; i<10; i++){
        int a;
        cin >>a;

        if(a%2==1){
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}