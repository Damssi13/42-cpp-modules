//the constructor takes the path to the csv.database

#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    if(ac != 2)
    {
        std::cerr << "Unvalid usage: ./btc [inputFile.txt]\n";
        exit(1);
    }
    try
    {
        BitcoinExchange coin("../data.csv");
        coin.parse(av[1]); //input.txt
    }
    catch(const std::runtime_error e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}