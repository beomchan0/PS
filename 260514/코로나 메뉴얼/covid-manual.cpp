#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    char a1,b1,c1;
    int a2,b2,c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

    int cnt=0;

    if(a1=='Y'&&a2>=37){
        cnt++;
    }

    if(b1=='Y'&&b2>=37){
        cnt++;
    }

    if(c1=='Y'&&c2>=37){
        cnt++;
    }

    if(cnt>=2){
        cout << "E";
    }else{
        cout << "N";
    }
    


    return 0;
}