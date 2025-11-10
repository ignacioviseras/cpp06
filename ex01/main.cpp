# include <iostream>
# include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 15;
	data.name = "paco";

	std::cout << "Content of data:\n" <<
				"id: " << data.id <<
				"\nname: " << data.name << std::endl;
	std::cout << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialize contetn " << raw << std::endl;
	
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Serialize contetn " << ptr << std::endl;

	if (ptr == &data)
		std::cout << "Deserialized ptr is equals" << std::endl;
	else
		std::cout << "pointer do not macht :(" << std::endl;

	std::cout << std::endl;
	std::cout << "Content of ptr:\n" <<
				"id: " << ptr->id <<
				"\nname: " << ptr->name << std::endl;
	return 0;
}

