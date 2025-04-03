#include "Fixed.hpp"




int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


Fixed j(5.5f);
Fixed i(4);

Fixed n = (j + i);
std::cout << "________________________\n";
std::cout << n << std::endl;
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;

return 0;
}