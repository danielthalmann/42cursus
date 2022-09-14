
#include "serialize.hpp"
#include <iostream>

void print_data(Data *data)
{
	std::cout << "data.id    :" << data->id << std::endl;
	std::cout << "data.value :" << data->value << std::endl;
}

int main ( void )
{
	std::cout << "define data" << std::endl;

	Data *data = new Data();

	data->id = 24;
	data->value = "test";

	print_data(data);

	uintptr_t ser = serialize(data);

	Data *data_d = deserialize(ser);

	print_data(data_d);


	delete data;
	
	return (0);
}
