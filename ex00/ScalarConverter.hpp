#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <sstream>

enum Type {
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {

	private:
    ScalarConverter();
	ScalarConverter(const ScalarConverter& cpy);
	ScalarConverter& operator=(const ScalarConverter& src);
	~ScalarConverter();

	public:
    static void 	convert(const std::string& literal);
	bool 			is_pseudo(const std::string& literal);
	bool			is_nonsense(const std::string& literal);
	void 			convert_to_char(const std::string& literal);
	void 			convert_to_int(const std::string& literal);
	void 			convert_to_float(const std::string& literal, Type type);
	void 			convert_to_double(const std::string& literal, Type type);
	void			convert_pseudo(const std::string& literal, Type type);
	void			convert_char(char c);
	void 			convert_types(const std::string& literal, Type type);
};

#endif

/*
Les méthodes statiques peuvent être appelées sans avoir besoin d'instancier un objet 
de la classe. Elles peuvent être appelées en utilisant la syntaxe 
NomDeLaClasse::NomDeLaMéthode(), tandis que les méthodes non statiques nécessitent 
une instance de la classe (Objet.nomDeLaMéthode()).*/