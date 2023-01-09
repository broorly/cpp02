#include <iostream>

#include"Fixed.hpp"
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
Fixed c = Fixed(2.06f);
a = Fixed(5);
a/=c;
std::cout << "a/=c" << a << std::endl;
return 0;
}