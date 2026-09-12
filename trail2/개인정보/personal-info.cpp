#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string name[5];
int height[5];
double weight[5];

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

bool cmp1(const man &a, const man &b){
    return a.name < b.name;
}

bool cmp2(const man &a, const man &b){
    return a.h > b.h;
}

man mans[5];

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> name[i] >> height[i] >> weight[i];
        mans[i] = man(name[i], height[i], weight[i]);
    }

    sort(mans, mans+5, cmp1);

    cout << "name\n";
    for(int i=0; i<5; i++){
        cout << mans[i].name << " " << mans[i].h << " ";
        cout << fixed;
        cout.precision(1);
        cout << mans[i].w << "\n";
        cout.unsetf(ios::fixed);
    }

    sort(mans, mans+5, cmp2);

    cout << "\nheight\n";
    for(int i=0; i<5; i++){
        cout << mans[i].name << " " << mans[i].h << " ";
        cout << fixed;
        cout.precision(1);
        cout << mans[i].w << "\n";
        cout.unsetf(ios::fixed);
    }



    // Please write your code here.

    return 0;
}