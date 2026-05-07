#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a+b+c;
    int mean = (a+b+c)/3;
    cout << sum << "\n" << mean << "\n" << sum - mean;
    return 0;
}