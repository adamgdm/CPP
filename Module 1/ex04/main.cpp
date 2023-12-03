#include "MySed.hpp"

int mySed(std::fstream &file, std::ofstream &filereplace,char *s1, char *s2)
{
    int lens1;
    int lens2;
    size_t pos;
    std::string line;
    std::string s1_str = s1;
    std::string s2_str = s2;

    while (std::getline(file, line))
    {
        lens1 = s1_str.length();
        lens2 = s2_str.length();
        while ((pos = (line.find(s1_str))) != std::string::npos)
        {
            line.erase(pos, lens1);
            line.insert(pos, s2_str);
        }
        filereplace << line << std::endl;
    }
    if (file.eof())
    {
        file.close();
        filereplace.close();
        return 0;
    }
    std::cout << "Error : File reading failed!" << std::endl;
    return 1;
}

std::string concatenate(const std::string& str1, const std::string& str2)
{
    return str1 + str2;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error : Number of arguments should be 3!" << std::endl;
        return 1;
    } 
    if (av[2][0] == '\0')
    {
        std::cout << "Error : Empty string!" << std::endl;
        return 1;
    }
    std::fstream file(av[1]);
    if (!file)
    {
        std::cout << "Error : File doesn't exist!" << std::endl;
        return 1;
    }
    std::ofstream filereplace(concatenate(av[1], ".replace"));
    return(mySed(file, filereplace, av[2], av[3]));
}