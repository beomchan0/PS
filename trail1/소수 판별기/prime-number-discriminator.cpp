#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N; 
    cin >> N;

    int flag=0;

    for(int i=2; i<N; i++){
        if(N%i==0){
            flag=1;
            break;
        }
    }

    if(flag==0){
        cout << "P";
    }else{
        cout << "C";
    }
    return 0;
}