#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    int sum=0;

    for(int i=1; i<=100; i++){
        sum+=i;

        if(sum>=N){
            cout << i;
            break;
        }
    }
    return 0;
}