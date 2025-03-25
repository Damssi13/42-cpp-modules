#include "Harl.hpp"


int main()
{
    Harl harl;


    harl.complain(NULL);
    harl.complain("WARNING");
    harl.complain("INFO");
    harl.complain("SOMETHING");
    harl.complain("DEBUG");
}