#include <iostream>

using namespace std;

int n, m;
int A[100];
int sum=0;

void f(){
    sum+=A[m-1];

    if(m%2==0){
        m/=2;
    }else{
        m-=1;
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    while(m!=1){
        f();
    }

    sum+=A[0];

    cout << sum;
    

    // Please write your code here.

    return 0;
}