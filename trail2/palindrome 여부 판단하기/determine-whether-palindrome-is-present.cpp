#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A;

bool ispal(string &s){
    string rs=s;
    reverse(rs.begin(), rs.end());

    if(s==rs){
        return true;
    }

    return false;
}

int main() {
    cin >> A;

    if(ispal(A)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    // Please write your code here.

    return 0;
}