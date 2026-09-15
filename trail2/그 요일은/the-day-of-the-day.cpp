#include <iostream>

using namespace std;

int m1, m2, d1, d2;
string A;
string day[7]={"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int num_of_day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int cal_day(int m, int d){
    int ans=0;
    for(int i=1; i<m; i++){
        ans+=num_of_day[i];
    }

    ans+=d;
    return ans;
}

int get_idx(string str){
    for(int i=0; i<7; i++){
        if(str==day[i]){
            return i;
        }
    }
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    int day1=cal_day(m1,d1);
    int day2=cal_day(m2,d2);

    int gap=day2-day1+1;

    int cnt=0;
    cnt+=gap/7;
    int idx=get_idx(A);

    if(idx<gap%7) cnt++;

    cout << cnt;

    





    // Please write your code here.

    return 0;
}