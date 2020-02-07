#pragma once

#include <iostream>
#include <string>

using namespace std;

class Staff
{
protected:
	string name;

public:
	void setName(string _name);
	virtual string getWriteName();
};

class Actor : public Staff
{
public:
	Actor();
	~Actor();

	string getWriteName() override;
};

class Director : public Staff
{
public:
	Director();
	~Director();

	string getWriteName() override;
};