#include <iostream>
using namespace std;

int main() {
    // Please write your code here.

    int a,b,c;
    cin >> a >> b >> c;

    int flag=0;

    for(int i=a; i<=b; i++){
        if(i%c==0){
            flag=1;
        }
    }

    if(flag==1){
        cout << "NO";
    }else{
        cout << "YES";
    }
    return 0;
}