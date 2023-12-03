#include "harl.hpp"

void Harl::debug( void )
{
    std::cout << "[DEBUG] This is a debug message" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[INFO] This is an info message" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[WARNING] This is a warning message" << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ERROR] This is an error message" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"debug", "info", "warning", "error"};
    void (Harl::*fncts[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
        {
            (this->*fncts[i])();
            return ;
        }
        i++;
    }
    std::cout << "[HARL] Invalid level " << level << std::endl;
}