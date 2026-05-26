#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    while(1){
        int a;
        cin >> a;
        if(a>4){
            cout << "Vacancy";
            break;
        }

        if(a==1){
            cout << "John\n";
        }else if(a==2){
            cout << "Tom\n";
        }else if(a==3){
            cout << "Paul\n";
        }else if(a==4){
            cout << "Sam\n";
        }
    }
    return 0;
}