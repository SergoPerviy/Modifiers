#pragma once
#include <string>
#include "Flat.hpp"

class House{
private:
	std::string street;
	size_t number;
	size_t floors;
	size_t flatsCounter;
	Flat* flatsArr;
public:
	House();
	House(std::string street, size_t number, size_t floors);
	~House();
	void appFlat(size_t, size_t rooms);
	void printFlat(size_t index) const;
};

