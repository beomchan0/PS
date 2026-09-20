#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N;
string cmd[10000];
int num[10000];

int main() {
    cin >> N;

    deque<int> d;
    for (int i = 0; i < N; i++) {
        cin >> cmd[i];
        if (cmd[i] == "push_front" || cmd[i] == "push_back") {
            cin >> num[i];

            if(cmd[i] == "push_front"){
                d.push_front(num[i]);
            }else{
                d.push_back(num[i]);
            }
        }else if(cmd[i] == "pop_front"){
            cout << d.front() << "\n";
            d.pop_front();
        }else if(cmd[i] == "pop_back"){
            cout << d.back() << "\n";
            d.pop_back();
        }else if(cmd[i]=="size"){
            cout << d.size() << "\n";
        }else if(cmd[i] == "empty"){
            if(d.empty()){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }else if(cmd[i] == "front"){
            cout << d.front() << "\n";
        }else if(cmd[i] == "back"){
            cout << d.back() << "\n";
        }
    }

    // Please write your code here.

    return 0;
}
