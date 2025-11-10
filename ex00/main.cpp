#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "The program need 2 params" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}