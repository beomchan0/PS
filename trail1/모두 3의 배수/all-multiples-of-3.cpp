#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int flag=0;

    for(int i=0; i<5; i++){
        int a;
        cin >> a;
        if(a%3!=0){
            flag=1;
            break;
        }
    }

    if(flag==0){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}