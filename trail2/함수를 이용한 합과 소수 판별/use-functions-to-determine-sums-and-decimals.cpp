#include <iostream>

using namespace std;

int a, b;

bool isprime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool is2(int n){
    int sum=0;
    while(n>0){
        sum+= n%10;
        n/=10;
    }

    if(sum%2==0){
        return true;
    }else{
        return false;
    }
}

bool ismagicnumber(int n){
    if(isprime(n)&&is2(n)){
        return true;
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