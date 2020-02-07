#include <iostream>

#include "Database.h"

using namespace std;

int main()
{
	cout << "Hello there! Welcome to the movie database project!" << endl;
	Database db;

	bool repeat = true;

	while (repeat) {

		char choice;

		cout << "\nWhat would you like to do? \n'1'-add a movie, \n'2'-view info about a specific, existing movie, \n'3'-delete a movie entry, \n'4'-view a list of all existing movies, \n'5'-search movies by actor, \n'6'-exit program.\n";

		cin >> choice;
		cin.ignore();

		switch (choice) {

		case '1': //ADD A MOVIE

		{
			db.AddMovie();
			break;
		}
		case '2': //VIEW INFO

		{
			db.ViewMovieInfo();
			break;
		}

		case '3': //DELETE ENTRY

		{
			db.DeleteMovie();
			break;
		}

		case '4':

		{
			db.ViewMovieList();
			break;
		}

		case '5':

		{
			db.SearchMoviesByActor();
			break;
		}

		case '6': 
		
		{ 
			repeat = false;
			break; 
		}

		default: cout << "that's not an allowed choice, restart and try again!" << endl;

		}
	}
	return 0;
}
