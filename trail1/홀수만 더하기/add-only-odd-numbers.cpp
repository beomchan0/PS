#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    int sum=0;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;

        if(a%2==1&&a%3==0){
            sum+=a;
        }
    }

    cout << sum;
    return 0;
}