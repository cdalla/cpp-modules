#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data data{156};
	Data *dataPtr = &data;
	
	uintptr_t seriaLizard = Serializer::serialize(dataPtr);
	Data *deseriaLizard = Serializer::deserialize(seriaLizard);
	
	if (deseriaLizard == dataPtr)
		std::cout << "Cast successfully!!!" << std::endl;
	else
		std::cerr << "Cast DID NOT work properly" << std::endl;
	
	return 0;
}