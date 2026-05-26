#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    int sum=0;
    int cnt=0;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        sum+=a;
        cnt++;
    }

    cout << sum << " ";
    cout << fixed;
    cout.precision(1);
    cout << (double)sum/cnt;
    return 0;
}