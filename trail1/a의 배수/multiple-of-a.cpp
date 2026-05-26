#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N,a;
    cin >> N >> a;

    int i=1;
    while(i<=N){
        if(i%a==0){
            cout << 1 << "\n";
        }else{
            cout << 0 << "\n";
        }
        i++;
    }
    return 0;
}