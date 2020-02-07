#pragma once

#include <iostream>
#include <vector>

#include "Staff.h"

using namespace std;

class MovieInfo {
private:
	int year = 0;
	vector <Staff*> staff;
	string description;

public:
	MovieInfo();
	~MovieInfo();

	void setYear(int y);
	int getYear();

	void setStaff(Staff* s);
	vector<Staff*> getStaff();
	int getStaffSize();
	void clearStaff();

	void setDesc(string d);
	string getDesc();

};
