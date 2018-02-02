#pragma once
#include <string>

class Field {

private:
	std::string name;

public:
	// status declare the status of a field
	// if free: the field isnt occupied, if busy: the field is occupied
	// if hit: The field was occupied and is hited now, if besides: The field wasn't occupied
	enum State { FREE = 1, BUSY = 2, HIT = 3, BESIDES = 4 } myState;

	Field();
	void setState(State status);
	Field::State getState();
};