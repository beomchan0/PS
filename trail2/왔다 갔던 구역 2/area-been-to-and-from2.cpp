#include <iostream>

using namespace std;

#define offset 1000

int n;
int x[100];
char dir[100];

int arr[2001];

int main() {
    cin >> n;
    int cur_x=0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];

        if(dir[i]=='L'){
            for(int j=cur_x-x[i]; j<cur_x; j++){
                arr[j+offset]++;
            }
            cur_x=cur_x-x[i];
        }else if(dir[i]=='R'){
            for(int j=cur_x; j<cur_x+x[i]; j++){
                arr[j+offset]++;
            }
            cur_x=cur_x+x[i];
        }
    }

    int cnt=0;

    for(int i=0; i<2001; i++){
        if(arr[i]>=2){
            cnt++;
        }
    }

    cout << cnt;

    // Please write your code here.

    return 0;
}