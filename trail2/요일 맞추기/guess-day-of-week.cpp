#include <iostream>

using namespace std;

int m1, d1, m2, d2;
string day[7]={"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int num_of_day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int cal_day(int m, int d){
    int ans=0;
    for(int i=1; i<m; i++){
        ans+=num_of_day[i];
    }

    ans+=d;
    return ans;
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    int day1=cal_day(m1,d1);
    int day2=cal_day(m2,d2);

    int gap=day2-day1;
    int idx=(gap%7+7)%7;
    cout << day[idx];



    // Please write your code here.

    return 0;
}