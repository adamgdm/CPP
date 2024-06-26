#include "Serializer.hpp"

int main()
{
    Data* Chinwi = new Data;

    // init data.

    Chinwi->id = 1;
    Chinwi->Name = "Chinwi";
    Chinwi->Surname = "Nor din";

    // Print Data of Chinwi before any function

    std::cout << UNDERLINE_BOLD_YELLOW << "Data before Serialization:" << RESET << std::endl;

    std::cout << BLUE << "  ID: " << RESET << Chinwi->id << std::endl;
    std::cout << BLUE << "  Name: " << RESET << Chinwi->Name << std::endl;
    std::cout << BLUE << "  Surname: " << RESET << Chinwi->Surname << std::endl << std::endl;

    // Print Pointer Address of Chinwi before any function

    std::cout << BLUE << "Pointer Address Before Serialization: " << RESET << Chinwi << std::endl;
    std::cout << BLUE << "      In DECIMAL: " << RESET << std::dec << (uintptr_t)Chinwi << std::endl << std::endl;

    // Serialize Chinwi

    uintptr_t ptr = Serializer::serialize(Chinwi);

    std::cout << YELLOW << "Serializing..." << RESET << std::endl;

    // Print Pointer Address of Chinwi after serialization in hexdecimal    

    std::cout << BLUE << "Pointer Address After Serialization: " << RESET << "0x" << std::hex << ptr << std::endl;
    std::cout << BLUE << "      In DECIMAL: " << RESET << std::dec << ptr << std::endl << std::endl;

    // Deserialize Chinwi

    Data *Chinwi2 = Serializer::deserialize(ptr);

    std::cout << YELLOW << "Deserializing..." << RESET << std::endl;

    // Print Pointer Address of Chinwi after deserialization

    std::cout << BLUE << "Pointer Address After Deserialization: " << RESET << Chinwi2 << std::endl;
    std::cout << BLUE << "      In DECIMAL: " << RESET << std::dec << (uintptr_t)Chinwi2 << std::endl << std::endl;

    // Print Data of Chinwi after deserialization

    std::cout << UNDERLINE_BOLD_YELLOW << "Data after Deserialization:" << RESET << std::endl;

    std::cout << BLUE << "  ID: " << RESET << Chinwi2->id << std::endl;
    std::cout << BLUE << "  Name: " << RESET << Chinwi2->Name << std::endl;
    std::cout << BLUE << "  Surname: " << RESET << Chinwi2->Surname << std::endl;

    delete Chinwi;

    return 0;
}