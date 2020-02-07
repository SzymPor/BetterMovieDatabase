#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "MovieInfo.h"

using namespace std;

class FileName
{
private:
	string line;

	string title;
	string ext = ".txt";

	string movieListPath = "movielist.txt";

	fstream moviefile;
	fstream movielist;
public:
	FileName();
	FileName(string _title);
	~FileName();

	string getTitle();
	void setTitle(string _title);

	string getFinalName();

	void createNewMovie(MovieInfo mi);

	void readMovieDetails();
	void readMovieList();

	void deleteMovieFile();

	void searchForActor(string actor);
};

