#include "Serializer.hpp"

Serializer::Serializer(void){};

Serializer::~Serializer(void){};

Serializer::Serializer(Serializer const &src)
{
	(void)src;
	
	return ;
}

Serializer & Serializer::operator=(Serializer const &src)
{
	(void)src;
	
	return *this;
}


uintptr_t Serializer::serialize(Data* ptr)
{
	if	(ptr == 0)
		return 0;
	
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
		return nullptr;
	
	return reinterpret_cast<Data *>(raw);
}

