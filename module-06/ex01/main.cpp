#include "Serializer.hpp"

int main(){
    Data data;
    data.i = 42;
    data.name = "Serializer";

    uintptr_t raw = Serializer::serialize(&data);

    Data *ptr = Serializer::deserialize(raw);

    std::cout << "Original Address : " << &data << std::endl;
    std::cout << "Serialized Value : " << raw << std::endl;
    std::cout << "Deserialized Ptr : " << ptr << std::endl;

    std::cout << "Data i : " << ptr->i << std::endl;
    std::cout << "Data name : " << ptr->name << std::endl;

    if (ptr == &data)
        std::cout << "Pointer matches!" << std::endl;
    else
        std::cout << "Pointer mismatch!" << std::endl;

    return 0;
}