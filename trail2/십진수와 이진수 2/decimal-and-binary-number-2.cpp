#include <iostream>

using namespace std;

string N;

int main() {
    cin >> N;

    int binary[20];
    int num10 = 0;

    int a=1;

    for(int i=0; i<N.length(); i++){
        num10 = num10*2 + (N[i]-'0');
    }

    num10*=17;
    int cnt=0;
    while(1){
        if(num10<2){
            binary[cnt++] = num10;
            break;
        }

        binary[cnt++] = num10%2;
        num10 /= 2;
    }

    for(int i=cnt-1; i>=0; i--){
        cout << binary[i];
    }

    

    // Please write your code here.

    return 0;
}