#include <iostream>
#include <string>

using namespace std;

bool f(string str){
    int arr[26]={0};
    for(int i=0; i<str.length(); i++){
        arr[str[i]-'a'] = 1;
    }

    int cnt=0;

    for(int i=0; i<26; i++){
        if(arr[i]==1){
            cnt++;
        }
    }

    if(cnt>=2){
        return true;
    }

    return false;
}

string A;

int main() {
    cin >> A;

    if(f(A)){
        cout << "Yes";
    }else{
        cout << "No";
    }

    // Please write your code here.

    return 0;
}