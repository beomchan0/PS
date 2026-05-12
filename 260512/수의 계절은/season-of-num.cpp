#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a;
    cin >> a;
    if(a>=12||a<=2){
        cout << "Winter";
    }else if(a>=9){
        cout << "Fall";
    }else if(a>=6){
        cout << "Summer";
    }else if(a>=3){
        cout << "Spring";
    }
    return 0;
}