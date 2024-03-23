#include "Serializer.hpp"

int main()
{
    Data* Chinwi = new Data;

    // init data.

    Chinwi->id = 1;
    Chinwi->Name = "Chinwi";
    Chinwi->Surname = "Nor din";

    // Print Data of Chinwi before any function

    std::cout << "Data before Serialization: " << std::endl;

    std::cout << "  ID: " << Chinwi->id << std::endl;
    std::cout << "  Name: " << Chinwi->Name << std::endl;
    std::cout << "  Surname: " << Chinwi->Surname << std::endl;

    // Print Pointer Address of Chinwi before any function

    std::cout << "Pointer Address Before Serialization: " << Chinwi << std::endl << std::endl;

    // Serialize Chinwi

    uintptr_t ptr = Serializer::serialize(Chinwi);

    std::cout << "Serializing..." << std::endl;

    // Print Pointer Address of Chinwi after serialization in hexdecimal    

    std::cout << "Pointer Address After Serialization: " << std::hex << ptr << std::endl << std::endl;

    // Deserialize Chinwi

    Data *Chinwi2 = Serializer::deserialize(ptr);

    std::cout << "Deserializing..." << std::endl;

    // Print Pointer Address of Chinwi after deserialization

    std::cout << "Pointer Address After Deserialization: " << Chinwi2 << std::endl << std::endl;

    // Print Data of Chinwi after deserialization

    std::cout << "Data after Deserialization: " << std::endl;

    std::cout << "  ID: " << Chinwi2->id << std::endl;
    std::cout << "  Name: " << Chinwi2->Name << std::endl;
    std::cout << "  Surname: " << Chinwi2->Surname << std::endl;

    delete Chinwi;

    return 0;
}