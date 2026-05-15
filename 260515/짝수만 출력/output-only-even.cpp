#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a,b;
    cin >> a >> b;
    int i=a;
    while(i<=b){
        if(i%2==0){
            cout << i << " ";
        }
        i++;
    }
    return 0;
}