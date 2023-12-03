#include "harl.hpp"

int main( void )
{
    Harl harl;

    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");
    harl.complain("inv");
    return 0;
}