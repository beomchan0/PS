#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int sum=0;
    int cnt=0;

    for(int i=0; i<10; i++){
        int a;
        cin >> a;
        if(a>=0&&a<=200){
            sum+=a;
            cnt++;
        }
    }

    cout << sum << " ";
    cout << fixed;
    cout.precision(1);
    cout << (double)sum/cnt;
    return 0;
}