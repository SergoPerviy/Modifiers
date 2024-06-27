#include "Flat.hpp"

Flat::Flat() : Flat (1, 1, 0) {}

Flat::Flat(size_t number, size_t rooms, size_t floor) {
	this->number = number;
	this->rooms = rooms;
	this->floor = floor;
}

Flat::Flat(const Flat& other) : Flat(other.number, other.rooms, other.floor) {}

size_t Flat::getNumber() const {return number;}

size_t Flat::getRooms() const {return rooms;}

size_t Flat::getFloor() const {return floor;}

