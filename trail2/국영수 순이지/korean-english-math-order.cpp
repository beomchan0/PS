#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_N 10

int n;
string name[10];
int korean[10];
int english[10];
int math[10];

class man{
    public:
        string name;
        int korean;
        int english;
        int math;

        man(string name, int korean, int english, int math){
            this->name=name;
            this->korean=korean;
            this->english=english;
            this->math=math;
        }

        man(){

        }
};

bool cmp(const man &a, const man &b){
    if(a.korean==b.korean){
        if(a.english==b.english){
            return a.math>b.math;
        }
        return a.english > b.english;
    }
    return a.korean > b.korean;
}

man mans[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> korean[i];
        cin >> english[i];
        cin >> math[i];

        mans[i] = man(name[i], korean[i], english[i], math[i]);
    }

    sort(mans, mans+n, cmp);

    for(int i=0; i<n; i++){
        cout << mans[i].name << " " << mans[i].korean << " " << mans[i].english << " " << mans[i].math << "\n";
    }



    // Please write your code here.

    return 0;
}