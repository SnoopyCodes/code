#include <iostream>

struct Base {
    void baseFunc() {
        std::cout << "Base function called" << std::endl;
    }
};
struct Derived : public Base {
    void derivedFunc() {
        std::cout << "Derived function called" << std::endl;
        // std::cout << privateMember; // Error: private members are not accessible
    }
};

int main() {
    Derived d;
    d.baseFunc();    // Calls Base::baseFunc()
    d.derivedFunc(); // Calls Derived::derivedFunc()
    // d.protectedMember; // Error: protected members are not accessible from outside
    return 0;
}