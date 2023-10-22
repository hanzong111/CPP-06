/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:37:45 by schuah            #+#    #+#             */
/*   Updated: 2023/10/22 15:19:12 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

uintptr_t serialize(Data *ptr)
{
	uintptr_t	uint;

	uint = reinterpret_cast<uintptr_t>(ptr);
	return (uint);
}

Data *deserialize(uintptr_t raw)
{
	Data *	ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

/* Reinterpret_cast typecasts any pointer to any other pointer */
int main(void)
{
	Data data;
	Data *dataPointer;
	uintptr_t unsignedIntPointer;

	data.name = "HANZ";
	data.age = 20;
	std::cout << "\n---------- EX01 Before Serialize ----------\n" << std::endl;
	std::cout << "Name: " << data.name << std::endl;
	std::cout << "Age: " << data.age << std::endl;
	std::cout << "Pointer: " << &data << std::endl;
	unsignedIntPointer = serialize(&data);
	std::cout << "\n---------- EX01 Serialized ----------\n" << std::endl;
	std::cout << "Name: " << data.name << std::endl;
	std::cout << "Age: " << data.age << std::endl;
	std::cout << "Pointer: " << &data << std::endl;
	std::cout << "Unsigned int pointer: " << &unsignedIntPointer << std::endl;
	dataPointer = deserialize(unsignedIntPointer);
	std::cout << "\n---------- EX01 Deserialized ----------\n" << std::endl;
	std::cout << "Name: " << dataPointer->name << std::endl;
	std::cout << "Age: " << dataPointer->age << std::endl;
	std::cout << "Pointer: " << dataPointer << std::endl;
	return (0);
}
