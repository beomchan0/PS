#include <iostream>
#include <string>

using namespace std;
#define MAX_N 100
int n;
string date[100];
string day[100];
string weather[100];

class dayy{
    public:
        string date;
        string day;
        string weather;

        dayy(string date, string day, string weather){
            this->date=date;
            this->day=day;
            this->weather=weather;
        }

        dayy() {}
};

dayy days[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> date[i] >> day[i] >> weather[i];
        days[i]=dayy(date[i], day[i], weather[i]);
    }

    int idx=-1;

    for(int i=0; i<n; i++){
        if(idx==-1){
            if(days[i].weather=="Rain"){
                idx=i;
            }
        }else{
            if(days[i].weather=="Rain"){
                if(days[i].date<days[idx].date){
                    idx=i;
                }
            }
        }
    }

    cout << days[idx].date << " " << days[idx].day << " " << days[idx].weather;

    // Please write your code here.

    return 0;
}