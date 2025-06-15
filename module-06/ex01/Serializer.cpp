#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other){
    (void)other;
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other){
    (void)other;
    return *this;
}

Serializer::~Serializer() {}


uintptr_t   serialize(Data* ptr){

}

Data*       deserialize(uintptr_t raw){

}
