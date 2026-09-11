#include <iostream>
#include <string>

using namespace std;

string product_name;
int product_code;

class product {
    public:
        string name;
        int code;

        product(string name="codetree", int code=50){
            this->name = name;
            this->code = code;
        }


};

int main() {
    cin >> product_name >> product_code;

    product product1=product();
    cout << "product " << product1.code << " is " << product1.name << "\n";

    product1 = product(product_name, product_code);

    cout << "product " << product1.code << " is " << product1.name << "\n";

    // Please write your code here.

    return 0;
}