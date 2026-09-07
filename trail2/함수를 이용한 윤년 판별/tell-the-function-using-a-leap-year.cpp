#include <iostream>

using namespace std;

int y;

bool isyoon(int a){
    if(a%100==0&&a%400!=0){
        return false;
    }else if(a%4==0){
        return true;
    }
    return false;
}

int main() {
    cin >> y;

    if(isyoon(y)){
        cout << "true";
    }else{
        cout << "false";
    }

    // Please write your code here.

    return 0;
}