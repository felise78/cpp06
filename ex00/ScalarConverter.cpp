#include "ScalarConverter.hpp"

// ----------------------------- PRIVATE COPELIAN ------------------------------ //

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) { (void)cpy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return(*this); }

ScalarConverter::~ScalarConverter() {}

// ---------------------------------- UTILS ----------------------------------- //

bool	ScalarConverter::is_pseudo(const std::string& literal) {

		std::string list[6] = {"+inf", "+inff", "-inf", "-inff", "nan", "nanf"};
		
		for (int i = 0; i != 6; ++i)
		{
			if (literal == list[i])
				return true;
		}
		return false;
}

bool	ScalarConverter::is_nonsense(const std::string& literal) {
		
		unsigned long i = 0;
		bool point = false;

		if (is_pseudo(literal))
			return false;
		if (literal.size() == 1 && literal[0] > 32 && literal[0] < 127)
			return false;
		if (literal[i] == '+' || literal[i] == '-')
			i++;
		for ( ; i != literal.size() - 1; ++i)
		{
			if (std::isdigit(literal[i]) == false)
			{
				if (literal[i] == '.' && point == false)
					point = true;
				else
					return true;
			}
		}
		if (std::isdigit(literal[literal.size() - 1]) == false && literal[literal.size() - 1] != 'f')
			return true;
		if (literal[literal.size() - 1] == 'f' && point == false)
			return true;
		if (literal[literal.size() - 1] == 'f' && literal[literal.size() - 2] == '.')
			return true;
		return false;
}

// ------------------------------ CONVERSIONS ------------------------------- //

void	ScalarConverter::convert_to_char(const std::string& literal) {

	std::istringstream iss(literal);
	double charValue;
	iss >> charValue;

	try {
		if (charValue < std::numeric_limits<char>::min() || charValue > std::numeric_limits<char>::max())
			throw std::invalid_argument("char: impossible");
		else if (charValue < 33 || charValue > 126)
				throw std::invalid_argument("char: Non displayable");
			char casted = static_cast<char>(charValue);
			std::cout << "char: " << casted << std::endl;
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	return;
}

void	ScalarConverter::convert_to_int(const std::string& literal) {

	std::istringstream iss(literal);
	double intValue;
	iss >> intValue;

	try {
		if (intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max())
			throw std::invalid_argument("int: impossible");
		int casted = static_cast<int>(intValue);
		std::cout << "int: " << casted << std::endl;
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	return;
}

void 	ScalarConverter::convert_to_float(const std::string& literal, Type type) {

	std::istringstream iss(literal);
	double floatValue;
	iss >> floatValue;
	std::ostringstream oss;
	oss << floatValue;

	try {
		if (floatValue < -std::numeric_limits<float>::max() || floatValue > std::numeric_limits<float>::max())
				throw std::invalid_argument("float: impossible");
			if (type == INT || ( type == FLOAT && iss.str().size() - 1 != oss.str().size()) 
				|| (type == DOUBLE && iss.str().size() != oss.str().size()))
				std::cout << "float: " << floatValue << ".0f" << std::endl;
			else 
				std::cout << "float: " << floatValue << "f" << std::endl;
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	return;
}

void	ScalarConverter::convert_to_double(const std::string& literal, Type type) {

	std::istringstream iss(literal);
	double doubleValue;
	iss >> doubleValue;
	std::ostringstream oss;
	oss << doubleValue;

	try {
		if (doubleValue < -std::numeric_limits<double>::max() || doubleValue > std::numeric_limits<double>::max())
				throw std::invalid_argument("double: impossible");
			if (type == INT || ( type == FLOAT && iss.str().size() - 1 != oss.str().size()) 
				|| (type == DOUBLE && iss.str().size() != oss.str().size()))
				std::cout << "double: " << doubleValue << ".0" << std::endl;
			else 
				std::cout << "double: " << doubleValue << std::endl;
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	return;
}

void	ScalarConverter::convert_char(char c)
{
	int value = c;
	
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << value << ".0f" << std::endl;
	std::cout << "double: " << value << ".0" << std::endl;
}

void	ScalarConverter::convert_pseudo(const std::string& literal, Type type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (type == FLOAT)
	{
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, (literal.size() - 1)) << std::endl;
	}
	else
	{
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
}

// --------------------------- MAIN FUNCTIONS ---------------------------- //

void 	ScalarConverter::convert_types(const std::string& literal, Type type)
{
	convert_to_char(literal);
	convert_to_int(literal);
	convert_to_float(literal, type);
	convert_to_double(literal, type);
}

void 	ScalarConverter::convert(const std::string& literal) {

	if (literal.empty())
		throw std::invalid_argument("error : argument is empty");
	
	ScalarConverter sc;

	if (sc.is_nonsense(literal))
		throw std::invalid_argument("error : put a [int,float,double] or pseudo [nan,nanf,+inf,+inff,-inf,-inff] as argument");
	
	if (sc.is_pseudo(literal))
	{
		if (literal == "nan" || literal == "+inf" || literal == "-inf")
			sc.convert_pseudo(literal, DOUBLE);
		else 
			sc.convert_pseudo(literal, FLOAT);
	}
	else if (literal.size() == 1 && std::isdigit(literal[0]) == false)
	{
		char c = literal[0];
		sc.convert_char(c);
	}
	else if (literal[literal.size() - 1] == 'f')
		sc.convert_types(literal, FLOAT);
	else if (literal.find('.') != std::string::npos)
		sc.convert_types(literal, DOUBLE);
	else
		sc.convert_types(literal, INT);
}