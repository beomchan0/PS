#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main() {
    cin >> str;

    sort(str.begin(), str.end());
    
    cout << str;

    // Please write your code here.

    return 0;
}