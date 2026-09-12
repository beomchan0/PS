#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_N 1000
int N;
int sequence[1000];

class number{
public:
    int seq;
    int num;

    number(int seq, int num){
        this->seq=seq;
        this->num=num;
    }

    number(){}
};

bool cmp(const number &a, const number &b){
    if(a.seq==b.seq){
        return a.num<b.num;
    }
    
    return a.seq < b.seq;
}

number numbers[MAX_N];


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
        numbers[i]=number(sequence[i],i);
    }

    sort(numbers,numbers+N, cmp);

    int ans[MAX_N];
    for(int i=0; i<N; i++){
        ans[numbers[i].num]=i+1;
        
    }
    for(int i=0; i<N; i++){
        
        cout << ans[i] << " ";
    }

    // Please write your code here.

    return 0;
}
