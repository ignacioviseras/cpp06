#pragma once

class Base
{
	public:
		virtual ~Base() {}
};


// Implement a Base class that has a public virtual destructor only. Create three empty
// classes A, B, and C, that publicly inherit from Base.

// These four classes don’t have to be designed in the Orthodox
// Canonical Form.


// Implement the following functions:
// Base * generate(void);
// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B", or "C".
// void identify(Base& p);
// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.
// Including the typeinfo header is forbidden.
// Write a program to test that everything works as expected.
//------------------------
// Implemente una clase Base que tenga únicamente un destructor virtual público. Crea tres vacios
// clases A, B y C, que heredan públicamente de Base.

// Estas cuatro clases no tienen que estar diseñadas en ortodoxo.
// Forma canónica.


// Implementar las siguientes funciones:
// Base * generar(nulo);
// Crea una instancia aleatoria de A, B o C y devuelve la instancia como un puntero Base. Sentir la libertad
// para usar lo que quieras para la implementación de elección aleatoria.
// identificación nula (Base* p);
// Imprime el tipo real del objeto al que apunta p: "A", "B" o "C".
// identificación nula (Base& p);
// Imprime el tipo real del objeto al que hace referencia p: "A", "B" o "C". Usando un puntero
// dentro de esta función está prohibido.
// Está prohibido incluir el encabezado typeinfo.
// Escribe un programa para probar que todo funciona como se esperaba.
