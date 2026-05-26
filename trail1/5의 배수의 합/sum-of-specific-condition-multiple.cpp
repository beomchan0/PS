#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int A,B;
    int sum=0;

    cin >> A >> B;

    if(A<=B){
        for(int i=A; i<=B; i++){
            if(i%5==0){
                sum+=i;
            }
        }
    }else{
        for(int i=B; i<=A; i++){
            if(i%5==0){
                sum+=i;
            }
        }
    }

    cout << sum;
    return 0;
}