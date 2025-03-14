#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    void    setFirstName(std::string name);
    void    setLastName(std::string name);
    void    setNickName(std::string name);
    void    setPhoneNumber(std::string number);
    void    setDarkestSecret(std::string secret);
    
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
};

#endif