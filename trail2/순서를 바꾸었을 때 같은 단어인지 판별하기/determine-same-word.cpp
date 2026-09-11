#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string word1;
string word2;

int main() {
    cin >> word1;
    cin >> word2;

    if(word1.length() != word2.length()){
        cout << "No";
    }else{
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        int flag=1;
        for(int i=0; i<word1.length(); i++){
            if(word1[i]!=word2[i]){
                flag=0;
            }
        }

        if(flag){
            cout << "Yes";
        }else{
            cout << "No";
        }
    }

    


    // Please write your code here.

    return 0;
}
