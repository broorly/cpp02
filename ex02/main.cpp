#include <iostream>

#include"Fixed.hpp"
int main( void ) {
	  Fixed a = 6;
	const Fixed b = 9;
	Fixed c;

// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << (a / b) << std::endl;	
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
 c = Fixed(2.06f);
//a = Fixed(5);
std:: cout << c << "yooooo"<< std::endl;
c = b+a;
std:: cout << c << std::endl;
return 0;
}