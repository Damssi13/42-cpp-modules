#include "Sed.hpp"

Sed::Sed() {}

int    Sed::setArguments(std::string newFilename, std::string newS1, std::string newS2)
{
    filename = newFilename;
    s1 = newS1;
    s2 = newS2;
    
    if(newS1.empty() || newS2.empty() || replaceSrings())
        return 1;
    return 0;
}

int    Sed::replaceSrings()
{
    std::ifstream finput(filename.c_str());//converting it to C-Style bc c++98 can't open string file
    if(!finput.is_open())
        return 1;

    std::string newFile = filename.append(".replace");

    std::ofstream foutput(newFile.c_str());
    if(!foutput.is_open())
        return 1;

    size_t pos;
    std::string str;
    while(std::getline(finput, str))
    {   
        pos = 0;
        pos = str.find(s1, pos);
        while(pos < str.length())
        {
            pos = 0;
            pos = str.find(s1, pos);
            if((int)pos != -1)
            {
                str.erase(pos, s1.length());
                str.insert(pos, s2);
            }
            else
                break;
        }
        foutput << str <<std::endl;
    }
    finput.close();
    foutput.close();
    return 0;
}
