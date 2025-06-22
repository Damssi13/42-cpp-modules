#include "Base.hpp"

Base::~Base(){}

Base    *generate()
{
    int i;
    srand(time(0));
    i = rand() % 3;
    if(i == 1)
        return new A();
    else if(i == 2)    
        return new B();
    else
        return new C();

}

void    identify(Base *p)
{
    if(dynamic_cast<A *>(p)) // why we did A* and not only A.
        std::cout << "A\n";
    else if(dynamic_cast<B *>(p)) 
        std::cout << "B\n";
    else if(dynamic_cast<C *>(p)) 
        std::cout << "C\n";
    else
        std::cout << "Unvalid Type\n";
}

void    identify(Base& p)
{
    try{
        (void)dynamic_cast<A &>(p);
        std::cout << "A\n";
        return ;
    }
    catch(std::exception &e){
        try{
            (void)dynamic_cast<B &>(p);
            std::cout << "B\n";
            return ;
        }
        catch(std::exception &e){
            try{
                (void)dynamic_cast<C &>(p);
                std::cout << "C\n";
                return ;
            }
            catch(std::exception &e){
                std::cout << "Unvalid Type\n";
            }
        }
    }
}