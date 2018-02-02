#include "Field.hpp"

Field::Field()
{
	myState = FREE;
}

void Field::setState(State newStatus)
{
	myState = newStatus;
}

Field::State Field::getState()
{
	return myState;
}