#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    if(ac != 2)
        std::cerr << "Unvalid usage: ./btc [inputFile.txt]\n";
    try
    {
        BitcoinExchange coin;
        coin.parse(av[1]);
    }
    catch(const std::runtime_error e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}