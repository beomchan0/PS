#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

int main() {
    cin >> str;

    stack<char> s;
    int ans=1;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='('){
            s.push('(');
        }else{
            if(s.empty()){
                cout << "No";
                return 0;
            }else{
                s.pop();
            }
        }
    }

    if(s.empty()){
        cout << "Yes";
    }else{
        cout << "No";
    }


    // Please write your code here.

    return 0;
}
