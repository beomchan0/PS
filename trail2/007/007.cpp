#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    string secret_code;
    char meeting_point;
    int time;

    cin >> secret_code >> meeting_point >> time;

    tuple<string, char, int> t=make_tuple(secret_code, meeting_point, time);

    cout << "secret code : " << get<0>(t) << "\n";
    cout << "meeting point : " << get<1>(t) << "\n";
    cout << "time : " << get<2>(t) << "\n";



    // Please write your code here.

    return 0;
}