#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 10

using namespace std;

int n;
string name[MAX_N], address[MAX_N], region[MAX_N];

class man{
    public:
        string name;
        string address;
        string region;

        man(string name, string address, string region){
            this->name = name;
            this->address=address;
            this->region=region;
        }

        man() {}
};

man mans[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i] >> address[i] >> region[i];
        mans[i] = man(name[i], address[i], region[i]);
    }

    sort(name, name+n);

    string key_name=name[n-1];
    int key_idx=0;
    for (int i = 0; i < n; i++) {
        if(mans[i].name==key_name){
            key_idx=i;
            break;
        }
    }

    cout << "name " << mans[key_idx].name << "\n";
    cout << "addr " << mans[key_idx].address << "\n";
    cout << "city " << mans[key_idx].region << "\n";

    // Please write your code here.

    return 0;
}
