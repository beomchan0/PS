#include <iostream>
#include <algorithm>

using namespace std;

int n;
string name[10];
int height[10];
int weight[10];

class man{
public:
    string name;
    int h;
    double w;

    man(string name, int h, double w){
        this->name=name;
        this->h=h;
        this->w=w;
    }

    man(){}
};

bool cmp(const man &a, const man &b){
    if(a.h==b.h){
        return a.w>b.w;
    }
    return a.h < b.h;
}

man mans[10];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> height[i] >> weight[i];
        mans[i] = man(name[i], height[i], weight[i]);
    }

    sort(mans, mans+n, cmp);

    for(int i=0; i<n; i++){
        cout << mans[i].name << " " << mans[i].h << " " << mans[i].w << "\n";
    }

    // Please write your code here.

    return 0;
}