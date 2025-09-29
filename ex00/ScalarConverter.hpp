#pragma once
#include <string>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cerrno>

#define PSEUDO_LITERAL_SIZE 6

enum Type {
	CHAR_T,
	INT_T,
	FLOAT_T,
	DOUBLE_T,
	PSEUDO_T,
	UNKNOWN_T
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &);
		ScalarConverter &operator=(ScalarConverter const &);
		~ScalarConverter();
		
		static Type getType(const std::string &input);
		static bool isInt(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isDouble(const std::string &input);
		static bool isPseudoLiteral(const std::string &input);
		static void view(double d, bool isPseudo) ;
	public:
		static void convert(std::string const &literal);
};






// Write a class ScalarConverter that will contain only one static method "convert"
// that will take as a parameter a string representation of a C++ literal in its most common
// form and output its value in the following series of scalar types:
// • char
// • int
// • float
// • double
// As this class doesn’t need to store anything at all, it must not be instantiable by users.
// Except for char parameters, only the decimal notation will be used.
// Examples of char literals: ’c’, ’a’, ...
// To make things simple, please note that non-displayable characters shouldn’t be used as
// inputs. If a conversion to char is not displayable, print an informative message.
// Examples of int literals: 0, -42, 42...
// Examples of float literals: 0.0f, -4.2f, 4.2f...
// You have to handle these pseudo-literals as well (you know, for science): -inff, +inff,
// and nanf.
// Examples of double literals: 0.0, -4.2, 4.2...
// You have to handle these pseudo-literals as well (you know, for fun): -inf, +inf, and
// nan.
// Write a program to test that your class works as expected.
// You have to first detect the type of the literal passed as a parameter, convert it from
// string to its actual type, then convert it explicitly to the three other data types. Lastly,
// display the results as shown below.
// If a conversion does not make any sense or overflows, display a message to inform
// the user that the type conversion is impossible. Include any header you need in order to
// handle numeric limits and special values.
// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
// -------------------
// Escriba una clase ScalarConverter que contendrá solo un método estático "convertir"
// que tomará como parámetro una representación de cadena de un literal de C++ en su forma más común
// Forme y genere su valor en la siguiente serie de tipos escalares:
// • char
// • unt
// • float
// • double
// Como esta clase no necesita almacenar nada en absoluto, los usuarios no deben poder crear instancias de ella.
// Excepto para los parámetros char, sólo se utilizará la notación decimal.
// Ejemplos de literales de caracteres: 'c', 'a', ...
// Para simplificar las cosas, tenga en cuenta que los caracteres no visualizables no deben usarse como
// entradas. Si no se puede mostrar una conversión a carácter, imprima un mensaje informativo.
// Ejemplos de literales int: 0, -42, 42...
// Ejemplos de literales flotantes: 0.0f, -4.2f, 4.2f...
// También tienes que manejar estos pseudoliterales (ya sabes, para la ciencia): -inff, +inff,
// y nanf.
// Ejemplos de literales dobles: 0.0, -4.2, 4.2...
// También tienes que manejar estos pseudoliterales (ya sabes, por diversión): -inf, +inf y
// yaya.
// Escribe un programa para probar que tu clase funciona como se esperaba.
// Primero debe detectar el tipo de literal pasado como parámetro, convertirlo de
// cadena a su tipo real, luego conviértala explícitamente a los otros tres tipos de datos. Por último,
// mostrar los resultados como se muestra a continuación.
// Si una conversión no tiene ningún sentido o se desborda, muestra un mensaje para informar
// al usuario que la conversión de tipo es imposible. Incluye cualquier encabezado que necesites para
// Manejar límites numéricos y valores especiales.
