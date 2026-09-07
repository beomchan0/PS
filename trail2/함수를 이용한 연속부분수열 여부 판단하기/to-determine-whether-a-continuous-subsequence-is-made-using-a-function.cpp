#include <iostream>

using namespace std;

int n1, n2;
int a[100], b[100];

bool f(int n){
    //a 의 시작점이 주어짐
    for(int i=0; i<n2; i++){
        if(a[n+i]!=b[i]){
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n1 >> n2;

    for (int i = 0; i < n1; i++) cin >> a[i];

    for (int i = 0; i < n2; i++) cin >> b[i];

    int flag=0;
    for(int i=0; i<=n1-n2; i++){
        if(f(i)){
            flag=1;
            break;
        }
    }

    if(flag==1){
        cout <<"Yes";
    }else{
        cout << "No";
    }

    // Please write your code here.

    return 0;
}