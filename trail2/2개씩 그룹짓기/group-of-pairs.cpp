#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[2000];

int main() {
    cin >> N;

    for (int i = 0; i < 2 * N; i++) {
        cin >> nums[i];
    }

    int sums[1000]={0};

    sort(nums, nums+2*N);
    
    for(int i=0; i<N; i++){
        sums[i] = nums[i]+nums[2*N-i-1];
    }

    sort(sums, sums+N);

    cout << sums[N-1];

    

    // Please write your code here.

    return 0;
}
