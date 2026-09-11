#include <iostream>
#include <string>

using namespace std;

string user2_id;
int user2_level;

class man {
    public:
        string id;
        int level;

        man(string id="codetree", int level=10) {
            this -> id = id;
            this -> level = level;
        }
};

int main() {
    cin >> user2_id >> user2_level;

    man man1 = man();

    man man2 = man(user2_id, user2_level);

    cout << "user " << man1.id << " lv " << man1.level << "\n";
    cout << "user " << man2.id << " lv " << man2.level << "\n";

    // Please write your code here.

    return 0;
}