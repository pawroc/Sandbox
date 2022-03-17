#include <iostream>

/**
 * @brief Junior level task:
 * - Constructor / destructor calling order
 * - virtual member functions call when creating / destroying an object
 * 
 */

class Base {
public:
    Base() {
        std::cout << "Base()\n";
        doSomething();
    }

    virtual ~Base() {
        std::cout << "~Base()\n";
        doSomething();
    }

    void doSomething() {
        std::cout << "\tdoSomething\n";
        doOther();
    }

private:
    virtual void doOther() {
        std::cout << "\t\tdoOther Base\n";
    }
};

class Member {
public:
    Member() { std::cout << "Member()\n"; }
    ~Member() { std::cout << "~Member()\n"; }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived()\n";
        doSomething();
    }

    ~Derived() {
        std::cout << "~Derived()\n";
        doSomething();
    }

private:
    void doOther() override {
        std::cout << "\t\tdoOther Derived\n";
    }

private:
    Member mem;
};

int main()
{
    Derived sut;
    return 0;
}