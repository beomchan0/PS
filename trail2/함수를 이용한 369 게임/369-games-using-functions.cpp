#include <iostream>

using namespace std;

int a, b;

bool ismagicnumber(int n){
    if(n%3==0){
        return true;
    }else{
        while(n>0){
            int ele=n%10;
            if(ele==3||ele==6||ele==9){
                return true;
            }
            n/=10;
        }
    }
    return false;
}

int main() {
    cin >> a >> b;
    int cnt=0;

    for(int i=a; i<=b; i++){
        if(ismagicnumber(i)){
            cnt++;
        }
    }

    cout << cnt;

    // Please write your code here.

    return 0;
}