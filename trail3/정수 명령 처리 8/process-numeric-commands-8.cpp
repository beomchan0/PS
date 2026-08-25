#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;
string command[10000];
int A[10000];
list<int> s;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_front" || command[i] == "push_back") {
            cin >> A[i];
            if (command[i]=="push_front"){
                s.push_front(A[i]);
            }else if (command[i]=="push_back"){
                s.push_back(A[i]);
            }
        }else if(command[i]=="pop_front"){
            cout << s.front() << "\n";
            s.pop_front();
        }else if(command[i]=="pop_back"){
            cout << s.back() << "\n";
            s.pop_back();
        }else if(command[i]=="size"){
            cout << s.size() << "\n";
        }else if(command[i]=="empty"){
            if(s.empty()){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(command[i]=="front"){
            cout << s.front() << "\n";
        }else if(command[i]=="back"){
            cout << s.back() << "\n"; 
        }
    }

    // Please write your code here.

    return 0;
}
