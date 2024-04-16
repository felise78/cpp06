#ifndef SERIALIZER_HPP
 #define SERIALIZER_HPP

	#include "Data.hpp"
	#include <stdint.h>

	class Serializer {

		private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& src);
		~Serializer();

		public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	};

#endif

// uintptr_t //

// uintptr_t est un type entier non signé défini dans les langages de programmation 
// C et C++. C'est un type entier qui est garanti d'être suffisamment grand pour 
// contenir la valeur d'un pointeur. Le type uintptr_t est spécifiquement conçu 
// pour être capable de représenter l'adresse de n'importe quel objet en mémoire 
// sous forme de valeur entière sans perdre d'informations.
// Il est couramment utilisé en programmation de bas niveau, notamment dans des 
// situations où vous devez effectuer des opérations arithmétiques ou logiques sur 
// des pointeurs comme s'ils étaient des entiers, ou lorsque vous devez stocker des 
// pointeurs sous forme de valeurs entières sans risquer de perte ou de troncation 
// de données.
// Une application courante de uintptr_t est en programmation système, notamment 
// dans des scénarios où vous manipulez directement des adresses mémoire, comme 
// dans les algorithmes d'allocation de mémoire, la gestion dynamique de la mémoire 
// ou l'implémentation de structures de données de bas niveau telles que les listes 
// chaînées ou les arbres.
// Il est important de noter que bien que uintptr_t puisse être utile dans certains 
// scénarios, il doit être utilisé avec prudence, car il implique la manipulation 
// de bas niveau des adresses mémoire et peut facilement conduire à des bugs, en 
// particulier s'il n'est pas manipulé correctement.

// reinterpret_cast<> //

// En C++, reinterpret_cast est un opérateur de conversion qui peut être utilisé pour 
// convertir un pointeur d'un type à un autre.
// Lorsque vous utilisez reinterpret_cast, le compilateur effectue une conversion 
// directe du type source au type cible, sans aucune vérification ou ajustement de type. 
// Cela signifie que reinterpret_cast n'effectue aucune conversion de données réelle, 
// il interprète simplement les bits de la mémoire d'une certaine manière, sans 
// modifier ces bits.
// Cela peut être très puissant mais aussi dangereux, car il ignore toutes les règles 
// de type de C++ et peut donc conduire à un comportement indéfini si les types ne 
// sont pas compatibles. Par exemple, si vous utilisez reinterpret_cast pour convertir 
// un pointeur d'un type de données à un autre, et que les types ne sont pas 
// compatibles, vous risquez d'accéder à des données incorrectes ou de provoquer des 
// erreurs de segmentation.