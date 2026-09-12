#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
#define MAX_N 1000

int N;
int x[1000];
int y[1000];

class dot{
    public:
        int x,y,num;

        dot(int x, int y,int num){
            this->x=x;
            this->y=y;
            this->num=num;
        }

        dot(){}
};

bool cmp(const dot &a, const dot &b){
    int dis1=abs(a.x) + abs(a.y);
    int dis2=abs(b.x) + abs(b.y);

    if(dis1==dis2){
        return a.num<b.num;
    }
    return dis1<dis2;
}

dot dots[MAX_N];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];

        dots[i]=dot(x[i],y[i],i+1);
    }

    sort(dots,dots+N,cmp);

    for(int i=0; i<N; i++){
        cout << dots[i].num <<"\n";
    }



    // Please write your code here.

    return 0;
}
