#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        int min=i;

        for(int j=i; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }

        int temp=arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    // Please write your code here.

    return 0;
}
