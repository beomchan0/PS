#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    // Please write your code here.
    int cnt=0;
    int n=A.length();

    for(int i=0; i<n-3; i++){
        if(A[i]=='('&&A[i+1]=='('){
            for(int j=i+2; j<n-1; j++){
                if(A[j]==')'&&A[j+1]==')'){
                    cnt++;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}