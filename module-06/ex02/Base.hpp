#ifndef BASE_HPP
#define BASE_HPP

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <ctime>

class Base{
public:
    virtual ~Base();
};

class A : public Base{};

class B : public Base{};

class C : public Base{};

Base    *generate();
void    identify(Base* p);
void    identify(Base& p);

#endif