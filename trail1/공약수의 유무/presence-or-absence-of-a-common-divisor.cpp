#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int A,B;
    cin >> A >> B;
    int flag=0;

    for(int i=A; i<=B; i++){
        if(1920%i==0&&2880%i==0){
            flag=1;
        }
    }

    if(flag==1){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}