#include <iostream>
#include <string>

using namespace std;

string text;
string pattern;

bool f(int idx){
    for(int i=0; i<pattern.length(); i++){
        if(text[idx+i]!=pattern[i]){
            return false;
        }
    }

    return true;
}

int main() {
    cin >> text;
    cin >> pattern;
    int flag=0;
    for(int i=0; i<=text.length()-pattern.length(); i++){
        if(f(i)){
            cout << i;
            flag=1;
            break;
        }
    }

    if(flag==0){
        cout << -1;
    }

    // Please write your code here.

    return 0;
}