#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "layout.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int i = std::rand() % 3;
	
	switch (i)
	{
		case (0): return new A();
		case (1): return new B();
		default: return new C();
	}
}

void identify(Base* p) {

    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "Object type:" GREEN " A" RESET << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "Object type:" GREEN " B" RESET << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "Object type:" GREEN " C" RESET << std::endl;
    }
	return;
}


void identify(Base& p) {

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << GREEN "- A -" RESET << std::endl;
	}
	catch (const std::exception &e) { std::cout << GREY2 << "NOT A" << std::endl; }
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << GREEN "- B -" RESET << std::endl;
	}
	catch (const std::exception &e) { std::cout << GREY2 << "NOT B" << std::endl; }
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << GREEN "- C -" RESET << std::endl;
	}
	catch (const std::exception &e) { std::cout << GREY2 << "NOT C" << std::endl; }
}

int main ()
{
	Base *ptr = generate();

	std::cout << GREY2 "**************" RESET << std::endl;
	identify(ptr);
	std::cout << GREY2 "**************" RESET << std::endl;
	identify(*ptr);
	std::cout << GREY2 "**************" RESET << std::endl;

}

/*
Le dynamic_cast est un opérateur de conversion utilisé dans la programmation orientée objet 
en C++ pour effectuer des conversions sûres entre les types de pointeurs et de références de 
classes. Il est principalement utilisé pour des conversions de types polymorphiques, 
c'est-à-dire lorsque vous avez une hiérarchie de classes avec des fonctions virtuelles.
*/