#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int cnt=0;

    while(1){
        int a;
        cin >> a;

        if(cnt==3){
            break;
        }

        if(a%2==0){
            cout << a/2<< "\n";
            cnt++;
        }
    }
    return 0;
}