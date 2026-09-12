#include <iostream>
#include <algorithm>

using namespace std;

int n;
int height[1000];
int weight[1000];

class man{
public:

    int h;
    double w;
    int num;

    man(int h, double w, int num){

        this->h=h;
        this->w=w;
        this->num=num;
    }

    man(){}
};

bool cmp(const man &a, const man &b){
    if(a.h==b.h){
        return a.w>b.w;
    }
    return a.h < b.h;
}

man mans[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> height[i] >> weight[i];
        mans[i] = man(height[i], weight[i],i+1);
    }

    sort(mans, mans+n, cmp);

    for(int i=0; i<n; i++){
        cout << mans[i].h << " " << mans[i].w << " "<< mans[i].num << "\n";
    }

    // Please write your code here.

    return 0;
}