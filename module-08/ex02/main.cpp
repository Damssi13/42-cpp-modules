#include "MutantStack.hpp"

int main()
{
    std::cout << "______________SUBJECT TEST_______________\n";
        MutantStack<int> mstack;
        std::cout << "------- Pushed 2 elements ------\n";
        mstack.push(5);
        mstack.push(17);
        std::cout << "------- Top element ------\n";
        std::cout << mstack.top() << std::endl;
        std::cout << "------- Poped 1 element ------\n";
        mstack.pop();
    
        std::cout << "------- Size of mstack ------\n";
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "------- Iterate on the stack ------\n";
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    
        std::cout << "------- Size of std::stack copying mstack ------\n";
        std::cout << s.size() << std::endl;

    std::cout << "__________ Basic Tests ___________\n";
    MutantStack<int> mstack1;
    mstack1.push(10);
    mstack1.push(20);
    std::cout << "Top: " << mstack1.top() << std::endl;
    mstack1.pop();
    std::cout << "Size: " << mstack1.size();




    std::cout << "\n__________ Iterator ___________\n";
        MutantStack<int> mstack2;
    for (int i = 1; i <= 5; ++i)
        mstack2.push(i * 10); // 10, 20, 30, 40, 50

    std::cout << "Iterating through stack:\n";
    for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
        std::cout << *it << " ";

    std::cout << "\n__________ Const_Iterator ___________\n";
        MutantStack<int> mstack3;
    mstack3.push(42);
    mstack3.push(84);

    MutantStack<int>::const_iterator cit = mstack3.begin();
    // *it += 1; if we tried to modify it will give us an error
    std::cout << "Const iterator value: " << *cit << std::endl;

}