#include <iostream>
#include <vector>

using namespace std;

int N;
string command[10000];
int num[10000];

int main() {
    cin >> N;

    vector<int> v;


    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_back") {
            cin >> num[i];
            v.push_back(num[i]);
        }else if(command[i]=="get"){
            cin >> num[i];
            cout << v[num[i]-1] << "\n";
        }else if(command[i]=="size"){
            cout << v.size() << "\n";
        }else if(command[i]=="pop_back"){
            v.pop_back();
        }
    }

    // Please write your code here.

    return 0;
}
