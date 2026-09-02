#include <iostream>
#include <string>

using namespace std;

string a;

int main() {
    cin >> a;

    int num=0;
    int flag=0;
    for(int i=0; i<a.length(); i++){
        if(a[i]=='0'){
            flag=1;
            a[i]='1';
            break;
        }
    }

    if(flag==0){
        a[a.length()-1]='0';
    }
    int k=1;
    for(int i=0; i<a.length(); i++){
        num+=k*(a[a.length()-i-1]-'0');
        k=k*2;
    }

    cout << num;

    // Please write your code here.

    return 0;
}