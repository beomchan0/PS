#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    for(int i=N; i<=100; i++){
        if(i>=90){
            cout << "A ";
        }else if(i>=80){
            cout << "B ";
        }else if(i>=70){
            cout << "C ";
        }else if(i>=60){
            cout << "D ";
        }else{
            cout << "F ";
        }
    }
    return 0;
}