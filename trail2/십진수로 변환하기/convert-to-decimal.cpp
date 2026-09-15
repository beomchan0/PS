#include <iostream>
#include <string>

using namespace std;

string binary;

int main() {
    cin >> binary;

    int ans=0;
    for(int i=0; i<binary.length(); i++){
        ans = ans*2 + (binary[i]-'0');
    }
    cout << ans;

    // Please write your code here.

    return 0;
}