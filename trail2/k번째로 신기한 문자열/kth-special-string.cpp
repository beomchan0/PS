#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
string t;
string str[100];

int main() {
    cin >> n >> k >> t;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    int len=t.length();

    string str2[100];
    int cnt=0;
    for(int i=0; i<n; i++){
        if(str[i].length()>=len){
            int flag=1;
            for(int j=0; j<len; j++){
                if(str[i][j]!=t[j]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                str2[cnt] = str[i];
                cnt++;
            }
        }
    }

    sort(str2,str2+cnt);

    cout << str2[k-1];

    // Please write your code here.

    return 0;
}