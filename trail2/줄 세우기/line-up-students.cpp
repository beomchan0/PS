#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000

int N;
int h[1000];
int w[1000];

class student{
    public:
        int h, w, num;

        student(int h, int w, int num){
            this->h=h;
            this->w=w;
            this->num=num;
        }

        student() {}
};

bool cmp(const student &a, const student &b){
    if(a.h==b.h){
        if(a.w==b.w){
            return a.num<b.num;
        }
        return a.w>b.w;
    }
    return a.h>b.h;
}

student students[MAX_N];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> h[i] >> w[i];

        students[i] = student(h[i], w[i], i+1);
    }

    sort(students, students+N, cmp);

    for(int i=0; i<N; i++){
        cout << students[i].h << " " << students[i].w << " " << students[i].num << "\n";
    }

    // Please write your code here.

    return 0;
}
