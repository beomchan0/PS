#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        if(a%2==1&&a%3==0){
            cout << a << "\n";
        }
    }
    return 0;
}