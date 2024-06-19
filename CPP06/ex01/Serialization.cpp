#include "Serialization.hpp"

Serialization::Serialization(){
}

Serialization::~Serialization(){
}

Serialization::Serialization(Serialization const & rhs){
	(void)rhs;
}

Serialization & Serialization::operator=(Serialization const & rhs){
    if ( this != &rhs )
		(void)rhs;
	return *this;
}

uintptr_t Serialization::serialize(Data * ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}