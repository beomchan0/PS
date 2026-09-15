#include <iostream>
#include <climits>

using namespace std;

int n;
int x1[100], x2[100];

int arr[101];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];

        for(int j=x1[i]; j<=x2[i]; j++){
            arr[j]++;
        }
    }


    int max_val=INT_MIN;

    for(int i=1; i<101; i++){
        if(arr[i]>max_val){
            max_val=arr[i];
        }
    }

    cout << max_val;
    // Please write your code here.

    return 0;
}