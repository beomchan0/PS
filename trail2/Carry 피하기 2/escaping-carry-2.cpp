#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int arr[20];

bool iscarry(int a, int b, int c){
    while(a!=0||b!=0||c!=0){
        if(a%10+b%10+c%10 >= 10){
            return false;
        }else{
            a/=10;
            b/=10;
            c/=10;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_val=INT_MIN;
    int flag=0;

    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int a=arr[i];
                int b=arr[j];
                int c=arr[k];

                if(iscarry(a,b,c)){
                    int sum=a+b+c;
                    max_val = max(sum,max_val);
                    flag=1;
                }

            }
        }
    }
    if(flag==1){
        cout << max_val;
    }else{
        cout << -1;
    }

    // Please write your code here.

    return 0;
}