#include "MovieInfo.h"

MovieInfo::MovieInfo() {}

MovieInfo::~MovieInfo() {}

void MovieInfo::setYear(int y) {
	year = y;
}

int MovieInfo::getYear() {
	return year;
}

void MovieInfo::setStaff(Staff* s) {
	staff.push_back(s);
}

vector<Staff*> MovieInfo::getStaff() {
	return staff;
}

int MovieInfo::getStaffSize() {
	return staff.size();
}

void MovieInfo::clearStaff() {
	staff.clear();
}

void MovieInfo::setDesc(string d) {
	description = d;
}

string MovieInfo::getDesc() {
	return description;
}