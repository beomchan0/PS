#include <iostream>

using namespace std;

int n;

bool ismagicnumber(int a){
    if(a%2==0){
        int sum = 0;
        sum = a/10 + a%10;
        if(sum%5==0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
    
}

int main() {
    cin >> n;

    if(ismagicnumber(n)){
        cout << "Yes";
    }else{
        cout << "No";
    }

    // Please write your code here.

    return 0;
}