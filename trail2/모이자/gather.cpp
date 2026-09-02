#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int min_dis=INT_MAX;

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            sum+=abs(i-j)*A[j];
        }

        min_dis = min(sum,min_dis);
    }

    cout << min_dis;

    // Please write your code here.

    return 0;
}