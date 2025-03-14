#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>

void    addSecret(Contact *newContact);
void    addPhoneNumber(Contact *newContact);
void    addNickName(Contact *newContact);
void    addLastName(Contact *newContact);
void    addFirstName(Contact *newContact);
std::string removeWhiteSpace(std::string str, size_t len);


class PhoneBook{
private:
    Contact contacts[8];
    int contactIndex;
public:
    PhoneBook();

    void    search();
    void    add();
    void    printContact(int index);

    // ~PhoneBook();
};

#endif