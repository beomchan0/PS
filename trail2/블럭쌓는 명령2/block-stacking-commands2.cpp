#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
int A[100], B[100];
int arr[101];

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];

        for(int j=A[i]; j<=B[i]; j++){
            arr[j]++;
        }
    }

    int max_val=INT_MIN;

    for(int i=1; i<=N; i++){
        if(arr[i]>max_val){
            max_val=arr[i];
        }
    }

    cout << max_val;



    // Please write your code here.

    return 0;
}