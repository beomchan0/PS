#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int A,B;
    int sum=0;
    int cnt=0;
    cin >> A >> B;

    for(int i=A; i<=B; i++){
        if(i%5==0||i%7==0){
            sum +=i;
            cnt++;
        }
    }

    cout << sum << " ";

    cout << fixed;
    cout.precision(1);
    double mean=(double)sum/cnt;
    cout << mean;
    return 0;
}