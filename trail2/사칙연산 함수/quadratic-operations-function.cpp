#include <iostream>

using namespace std;

int a;
int d;
char o;

int f(int m,int n, char c){
    if(c=='+'){
        return m+n;
    }else if(c=='-'){
        return m-n;
    }else if(c=='*'){
        return m*n;
    }else if(c=='/'){
        return m/n;
    }
}

int main() {
    cin >> a >> o >> d;
    int ans=0;
    if(o=='+'||o=='-'||o=='*'||o=='/'){
        cout << a << " " << o << " " << d << " = " << f(a,d,o);
    }else{
        cout << "False";
    }
    

    // Please write your code here.

    return 0;
}