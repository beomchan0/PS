#include <iostream>
#include <climits>
using namespace std;

int n;
int numbers[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int max_val=INT_MIN;

    for(int i=0; i<n-2; i++){
        for(int j=i+2; j<n; j++){
            int sum=0;
            sum=numbers[i]+numbers[j];
            max_val=max(sum,max_val);
        }
    }

    cout << max_val;

    // Please write your code here.

    return 0;
}