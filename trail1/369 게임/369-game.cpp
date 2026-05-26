#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        int num=i;

        if(num%3==0){
            cout << 0 << " ";
            continue;
        }

        int flag=0;
        while(num>0){
            if((num%10)%3==0&&num%10!=0){
                flag=1;
                break;
            }else{
                num = num/10;
            }
        }
        if(flag==1){
            cout << 0 << " ";

        }else{
            cout << i << " ";
        }
    }
    return 0;
}