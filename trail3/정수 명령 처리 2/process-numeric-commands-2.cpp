#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string command[10000];
int A[10000];

int main() {
    cin >> N;

    queue<int> q;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push") {
            cin >> A[i];
            q.push(A[i]);
        }else if(command[i]=="pop"){
            cout << q.front() << "\n";
            q.pop();
        }else if(command[i]=="size"){
            cout << q.size() << "\n";
        }else if(command[i]=="empty"){
            if(q.empty()){
                cout << "1\n";

            }else{
                cout << "0\n";
            }
        }else if(command[i]=="front"){
            cout << q.front() << "\n";
        }
    }

    // Please write your code here.

    return 0;
}