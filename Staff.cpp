#include "Staff.h"

void Staff::setName(string _name)
{
	name = _name;
}

string Staff::getWriteName() 
{
	return name;
}

Actor::Actor() {}
Actor::~Actor() {}

string Actor::getWriteName()
{
	return "(Actor) " + name;
}

Director::Director() {}
Director::~Director() {}

string Director::getWriteName()
{
	return "(Director) " + name;
}