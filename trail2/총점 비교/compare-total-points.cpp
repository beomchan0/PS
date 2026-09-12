#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 10

int n;
string name[10];
int score1[10];
int score2[10];
int score3[10];

class man{
    public:
        string name;
        int score1;
        int score2;
        int score3;

        man(string name, int score1, int score2, int score3){
            this->name=name;
            this->score1=score1;
            this->score2=score2;
            this->score3=score3;
        }

        man(){}
};

bool cmp(const man &a, const man &b){
    return a.score1+a.score2+a.score3 < b.score1+b.score2+b.score3;
}

man mans[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> score1[i];
        cin >> score2[i];
        cin >> score3[i];
        mans[i] = man(name[i], score1[i], score2[i], score3[i]);
    }

    sort(mans, mans+n, cmp);

    for(int i=0; i<n; i++){
        cout << mans[i].name << " " << mans[i].score1 << " " << mans[i].score2 << " " << mans[i].score3 << "\n";
    }

    // Please write your code here.

    return 0;
}