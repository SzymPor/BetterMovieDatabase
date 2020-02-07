#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "FileName.h"
#include "MovieInfo.h"
#include "Staff.h"

using namespace std;

class Database
{
private:
	string sTemp;
	int nTemp;

	Actor* tempActor;
	Director* tempDirector;

	FileName fn;
	MovieInfo mi;

public:
	Database();
	~Database();

	void AddMovie();
	void ViewMovieInfo();
	void ViewMovieList();
	void DeleteMovie();
	void SearchMoviesByActor();
};

