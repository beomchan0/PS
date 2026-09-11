#include <iostream>
#include <string>

using namespace std;

string unlock_code;
char wire_color;
int seconds;

class bb{
    public:
        string code;
        char color;
        int sec;

        bb(string code, char color, int sec){
            this->code=code;
            this->color=color;
            this->sec=sec;
        }
};

int main() {
    cin >> unlock_code >> wire_color >> seconds;

    bb bb1 = bb(unlock_code, wire_color, seconds);

    cout << "code : " << bb1.code << "\n";
    cout << "color : " << bb1.color << "\n";
    cout << "second : " << bb1.sec << "\n";
    // Please write your code here.

    return 0;
}