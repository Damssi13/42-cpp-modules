#include "Base.hpp"

int main()
{
        Base* obj = generate();
        identify(obj);   // using pointer
        identify(*obj);  // using reference
        delete obj;
}