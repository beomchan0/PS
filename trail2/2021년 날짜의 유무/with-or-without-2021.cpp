#include <iostream>

using namespace std;

int M, D;

bool isreal(int a, int b){
    if(a==2){
        if(b>28){
            return false;
        }else{
            return true;
        }
    }else if(a<=7&&a%2==1){
        if(b>31){
            return false;
        }else{
            return true;
        }
    }else if(a<=7&&a%2==0){
        if(b>30){
            return false;
        }else{
            return true;
        }
    }else if(a<=12&&a%2==0){
        if(b>31){
            return false;
        }else{
            return true;
        }
    }else if(a<=12&&a%2==1){
        if(b>30){
            return false;
        }else{
            return true;
        }
    }
    return false;
}

int main() {
    cin >> M >> D;

    if(isreal(M,D)){
        cout << "Yes";
    }else{
        cout << "No";
    }

    // Please write your code here.

    return 0;
}