#include <iostream>

class Base {
public:
    virtual void show() { std::cout << "Base\n"; }
    virtual ~Base() { std::cout << "Base destroyed\n"; } // Virtual destructor
};

class Derived : public Base {
public:
    void show(){ std::cout << "Derived\n"; }
    ~Derived(){ std::cout << "Derived destroyed\n"; } // Derived destructor
};

int main() {
    Base* b = new Derived();
    b->show(); // Outputs "Derived"
    delete b;  // Properly calls Derived's destructor, then Base's
    return 0;
}