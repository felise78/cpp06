#include "Data.hpp"
#include "Serializer.hpp"
#include "layout.hpp"
#include <iostream>

int	main(void)
{
	uintptr_t 	serialized;
	Data		data;
	Data 		*empty = NULL;

	data.str = "quarante-deux";
	data.c = '*';
	data.nb = 42;
	data.fnb = 42.02f;
	data.dnb = 42.02;

	std::cout << GRY1 "**************************************" << std::endl;
	std::cout << "VALUES INSIDE DATA STRUCT :" << std::endl;
	std::cout << "**************************************" RESET << std::endl;

	std::cout << GRY2 "A - str value :\t\t" MINT << data.str << RESET << std::endl;
	std::cout << GRY2 "A - char value :\t" MINT << data.c << RESET << std::endl;
	std::cout << GRY2 "A - int value :\t\t" MINT << data.nb << RESET << std::endl;
	std::cout << GRY2 "A - float value :\t" MINT << data.fnb << RESET << std::endl;
	std::cout << GRY2 "A - double value :\t" MINT << data.dnb << RESET << std::endl;
	std::cout << GRY2 "A - addr value :\t" MINT << &data << RESET << std::endl;
	std::cout << std::endl;

	// serializing
	serialized = Serializer::serialize(&data);
	
	std::cout << GRY2 "///////// SERIALIZED VALUE ///////////" RESET << std::endl;

	std::cout << GRY2 "Result value :\t       " MINT << serialized << RESET << std::endl;
	std::cout << std::endl;

	// deserializing
	empty = Serializer::deserialize(serialized);

	std::cout << GRY1 "**************************************" << std::endl;
	std::cout << "VALUES INSIDE EMPTY STRUCT :" << std::endl;
	std::cout << "**************************************" RESET << std::endl;

	std::cout << GRY2 "A - str value :\t\t" MINT << empty->str << RESET << std::endl;
	std::cout << GRY2 "A - char value :\t" MINT << empty->c << RESET << std::endl;
	std::cout << GRY2 "A - int value :\t\t" MINT << empty->nb << RESET << std::endl;
	std::cout << GRY2 "A - float value :\t" MINT << empty->fnb << RESET << std::endl;
	std::cout << GRY2 "A - double value :\t" MINT << empty->dnb << RESET << std::endl;
	std::cout << GRY2 "A - addr value :\t" MINT << &empty << RESET << std::endl;
	std::cout << std::endl;

	std::cout << GRY1 "**************************************" RESET << std::endl;
	if (&data == empty)
		std::cout << MINT "C pointe vers A" RESET << std::endl;
	else
		std::cout << REDD "C ne pointe pas vers A" RESET << std::endl;
	std::cout << GRY1 "**************************************" RESET << std::endl << std::endl;

	return (0);
}