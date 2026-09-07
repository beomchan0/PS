#include <iostream>

using namespace std;

int n, m;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main() {
    cin >> n >> m;

    swap(&n, &m);
    cout << n << " " << m;

    // Please write your code here.

    return 0;
}