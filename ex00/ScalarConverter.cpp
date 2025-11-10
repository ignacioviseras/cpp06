#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	return *this;
}


/*
    nan 0.0/0.0
    nanf 0.0f/0.0f
    +inf 1.0/0.0 positive infinite
    -inf negative infinite
    +inff 1.0/0.0 float positive infinite
    -inff -1.0/0.0 float negative infinite

*/
static std::string pseudoLiterals[] = {
    "-inff", "+inff", "nanf",
    "-inf",  "+inf",  "nan"
};

bool ScalarConverter::isInt(const std::string &input) {
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.size())
		return false;
	for (; i < input.size(); i++)
		if (!std::isdigit(input[i]))
			return false;
	return true;
}

bool ScalarConverter::isFloat(const std::string &input) {
	bool dot = false;
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; i < input.size(); i++) {
		if (input[i] == '.' && !dot) {
			dot = true;
			continue;
		}
		if (i == input.size() - 1 && input[i] == 'f' && dot)
			return true;
		if (!std::isdigit(input[i]))
			return false;
	}
	return false;
}

bool ScalarConverter::isDouble(const std::string &input) {
	bool dot = false;
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; i < input.size(); i++) {
		if (input[i] == '.' && !dot) {
			dot = true;
			continue;
		}
		if (!std::isdigit(input[i]))
			return false;
	}
	return dot;
}

bool ScalarConverter::isPseudoLiteral(const std::string &input) {
	for (size_t i = 0; i < PSEUDO_LITERAL_SIZE; i++)
	{
		if (pseudoLiterals[i] == input)
			return (true);
	}
	return (false);
}

Type ScalarConverter::getType(const std::string &input) {
	if (input.size() == 1 && !std::isdigit(input[0]))
		return CHAR_T;
	if (isPseudoLiteral(input))
		return PSEUDO_T;
	if (isInt(input))
		return INT_T;
	if (isFloat(input))
		return FLOAT_T;
	if (isDouble(input))
		return DOUBLE_T;
	return UNKNOWN_T;
}

void ScalarConverter::view(double d, bool isPseudo) {

    std::cout << "char: ";
	if (isPseudo || d < 0 || d > 127 || !std::isprint(static_cast<int>(d)))
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

	std::cout << "int: ";
	if (isPseudo || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	float f = static_cast<float>(d);
	if (std::isnan(f))
        std::cout << "nanf";
	else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff");
	else {
		std::cout << f;
		if (f == static_cast<int>(f))
            std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if (std::isnan(d))
        std::cout << "nan";
	else if (std::isinf(d))
	{
		if (d > 0)
        	std::cout << "+inf";
		else
       		std::cout << "-inf";

	}
	else {
		std::cout << d;
		if (d == static_cast<int>(d))
            std::cout << ".0";
	}
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string const &literal) {
	Type type = getType(literal);
	double d = 0.0;
	bool isPseudo = false;

	switch (type) {
		case CHAR_T:
			d = static_cast<double>(literal[0]);
			break;
		case INT_T:
			d = static_cast<double>(std::atoi(literal.c_str()));
			break;
		case FLOAT_T:
			d = static_cast<double>(std::atof(literal.c_str()));
			break;
		case DOUBLE_T:
			d = std::atof(literal.c_str());
			break;
		case PSEUDO_T:
			isPseudo = true;
			if (literal[0] == '-')
                d = -std::numeric_limits<double>::infinity();
			else if (literal[0] == '+')
                d = std::numeric_limits<double>::infinity();
			else
                d = std::numeric_limits<double>::quiet_NaN();
			break;
		default:
			std::cout << "char: impossible\n" <<
						"int: impossible\n" <<
						"float: impossible\n" <<
						"double: impossible"
						<< std::endl;
			return;
	}
	view(d, isPseudo);
}