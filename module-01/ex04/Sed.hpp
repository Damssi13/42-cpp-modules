#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <string>

class Sed{
private:
    std::string filename;
    std::string s1;
    std::string s2;
public:
    Sed();
    int    setArguments(std::string newFilename, std::string newS1, std::string newS2);
    int    replaceSrings();
};

#endif