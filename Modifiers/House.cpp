#include "House.hpp"
#pragma once
#include <iostream>

House::House() : House("", 1, 1){}

House::House(std::string street, size_t number, size_t floors){
	this->street = street;
	this->number = number;
	this->floors = floors;
	this->flatsCounter = 0;
	this->flatsArr = nullptr;
}

House::~House(){
	delete[] flatsArr;
}

void House::appFlat(size_t floor, size_t rooms){
	Flat newFlat(++flatsCounter, rooms, floor);

	if (flatsArr == nullptr) {
		flatsArr = new Flat[1];
		flatsArr[0] = newFlat;
		return;
	}

	Flat* tmp = new Flat[flatsCounter];
	for (size_t i = 0; i < flatsCounter - 1; ++i)
		tmp[i] = flatsArr[i];
	tmp[flatsCounter - 1] = newFlat;
	delete[] flatsArr;
	flatsArr = tmp;
}

void House::printFlat(size_t index) const {
	std::cout << "Number: " << flatsArr[index].getNumber() << std::endl;
	std::cout << "Rooms: " << flatsArr[index].getRooms() << std::endl;
	std::cout << "Floor: " << flatsArr[index].getFloor() << std::endl;
}
