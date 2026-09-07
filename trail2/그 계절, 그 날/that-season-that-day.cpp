#include <iostream>
#include <string>

using namespace std;

bool isyoon(int a){
    if(a%100==0&&a%400!=0){
        return false;
    }else if(a%4==0){
        return true;
    }

    return false;
}

bool isreal(int a, int b, int c){
    if(a==2){
        if(isyoon(c)){
            if(b>29){
                return false;
            }else{
                return true;
            }
        }
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


int season(int a){
    if(a>=3&&a<=5){
        return 0; 
    }else if(a>=6 && a<=8){
        return 1;
    }else if(a>=9 && a<=11){
        return 2;
    }else{
        return 3;
    }
}

int Y, M, D;

int main() {
    cin >> Y >> M >> D;

    string seas[4]={"Spring", "Summer", "Fall", "Winter"};

    if(isreal(M,D,Y)){
        cout << seas[season(M)];
    }else{
        cout << -1;
    }

    // Please write your code here.

    return 0;
}