#include <iostream>

using namespace std;

int a, b;

bool f(int n){
    if(n%2==0){
        return false;
    }else if(n%10==5){
        return false;
    }else if(n%3==0&&n%9!=0){
        return false;
    }

    return true;
}

int main() {
    cin >> a >> b;

    int cnt=0;

    for(int i=a; i<=b; i++){
        if(f(i)){
            cnt++;
        }
    }

    cout << cnt;

    // Please write your code here.

    return 0;
}