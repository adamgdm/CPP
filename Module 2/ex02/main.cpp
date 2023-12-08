#include "Fixed.hpp"

int main( void ) 
{
/*    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
*/
    Fixed a(0); 
    Fixed b(10.5f); 
    Fixed c(2);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    // Test pre-increment
    std::cout << "++a: " << ++a << std::endl;

    // Test post-increment
    std::cout << "a++: " << a++ << std::endl;

    // Test pre-decrement
    std::cout << "--b: " << --b << std::endl;

    // Test post-decrement
    std::cout << "b--: " << b-- << std::endl;

    // Test addition
    std::cout << "a + b: " << a + b << std::endl;

    // Test subtraction
    std::cout << "a - b: " << a - b << std::endl;

    // Test multiplication
    std::cout << "a * c: " << a * c << std::endl;

    // Test division
    if (c != 0) {
    std::cout << "b / c: " << b / c << std::endl;
    }

    // Test min
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;

    // Test max
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

    return 0;
}