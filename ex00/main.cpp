#include "ScalarConverter.hpp"

int main (int ac, char** av)
{
	if (ac == 2)
	{
		try {
			ScalarConverter::convert(av[1]);
		} catch (const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "error : this program takes (only) 1 argument" << std::endl;
	return 0;
}