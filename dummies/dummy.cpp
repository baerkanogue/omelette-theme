// omelette
#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    string name;
    Animal(string n) :name(n) {}
    void speak() { cout << name << " speaks\n"; }
};

int add(int a, int b) { return a + b; }

int main() {
    int x = 5;
    float y = 3.14;
    bool ok = true;

    vector<int> v = {1,2,3};

    Animal cat("Cat");
    cat.speak();

    for (int i = 0; i < 2; i++)
        cout << i << (i % 2 == 0 ? " even" : " odd") << "\n";

    cout << add(2, 3) << "\n";
}