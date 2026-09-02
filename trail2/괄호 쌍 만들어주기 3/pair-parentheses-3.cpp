#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;
    int n = A.size();
    int ans=0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[i]=='('&&A[j]==')'){
                ans++;
            }
        }
    }

    cout << ans;

    // Please write your code here.

    return 0;
}