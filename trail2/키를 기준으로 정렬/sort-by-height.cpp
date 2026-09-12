#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define Max_n 10

int n;
string name[10];
int height[10];
int weight[10];

class man{
    public:
        string name;
        int height;
        int weight;

        man(string name, int height, int weight){
            this->name=name;
            this->height=height;
            this->weight=weight;
        }

        man(){

        }

};

bool cmp(const man &a, const man &b){
    return a.height < b.height;
}

man mans[Max_n];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> height[i];
        cin >> weight[i];

        mans[i] = man(name[i], height[i], weight[i]);
    }

    sort(mans, mans+n, cmp);

    for(int i=0; i<n; i++){
        cout << mans[i].name << " " << mans[i].height << " " << mans[i].weight << "\n";
    }

    // Please write your code here.

    return 0;
}