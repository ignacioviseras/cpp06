#pragma once
#include <stdint.h>
#include "Data.hpp"


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};



// Implement a class Serializer, which will not be initializable by the user in any way,
// with the following static methods:
// uintptr_t serialize(Data* ptr);
// It takes a pointer and converts it to the unsigned integer type uintptr_t.
// Data* deserialize(uintptr_t raw);
// It takes an unsigned integer parameter and converts it to a pointer to Data.
// Write a program to test that your class works as expected.
// You must create a non-empty (meaning it has data members) Data structure.
// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
// Do not forget to turn in the files of your Data structure.
//---------------
// Implemente una clase Serializador, que el usuario no podrá inicializar de ninguna manera.
// con los siguientes métodos estáticos:
// uintptr_t serializar(Datos* ptr);
// Toma un puntero y lo convierte al tipo entero sin signo uintptr_t.
// Datos* deserializar(uintptr_t raw);
// Toma un parámetro entero sin signo y lo convierte en un puntero a Datos.
// Escribe un programa para probar que tu clase funciona como se esperaba.
// Debe crear una estructura de datos que no esté vacía (lo que significa que tenga miembros de datos).
// Utilice serialize() en la dirección del objeto de datos y pase su valor de retorno a
// deserializar(). Luego, asegúrese de que el valor de retorno de deserialize() sea igual al
// puntero original.
// No olvides entregar los archivos de tu estructura de datos.