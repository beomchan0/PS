#include <iostream>

using namespace std;

int a, b;
string n;

int main() {
    cin >> a >> b;
    cin >> n;

    int num10=0;

    for(int i=0; i<n.length(); i++){
        num10 = num10*a + (n[i]-'0');
    }

    int arr[100];
    int cnt=0;
    while(1){
        if(num10<b){
            arr[cnt++] = num10;
            break;
        }

        arr[cnt++] = num10%b;
        num10/=b;
    }
    for(int i=cnt-1; i>=0; i--){
        cout << arr[i];
    }

    // Please write your code here.

    return 0;
}