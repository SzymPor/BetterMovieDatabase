#include "FileName.h"

FileName::FileName() {}

FileName::FileName(string _title) {
	title = _title;
}

FileName::~FileName() {}


string FileName::getTitle() {
	return title;
}

void FileName::setTitle(string _title) {
	title = _title;
}

string FileName::getFinalName() {
	return title + ext;
}

void FileName::createNewMovie(MovieInfo mi) {
	moviefile.open(getFinalName().c_str(), ios::out);
	movielist.open(movieListPath, ios::app);

	movielist << getTitle() << endl;

	moviefile << getTitle() << " (" << mi.getYear() << ")" << endl << endl;
	moviefile << "Staff:" << endl;
	for (int i = 0; i < mi.getStaffSize(); i++)
	{
		moviefile << mi.getStaff().at(i)->getWriteName() << endl;
	}
	moviefile << "\nSynopsis:\n" << mi.getDesc();

	movielist.close();
	moviefile.close();
}

void FileName::readMovieDetails() {
	moviefile.open(getFinalName().c_str(), ios::in);

	if (!moviefile)
	{
		cerr << "\nUnable to get info, perhaps the archives are incomplete?";
	}
	else
	{
		cout << "\n" << moviefile.rdbuf() << "\n";
	}

	moviefile.close();
}

void FileName::readMovieList() {
	movielist.open(movieListPath.c_str(), ios::in);

	if (!movielist)
	{
		cerr << "Database is empty, you need to add some movies." << endl;
	}
	else
	{
		movielist.seekg(0, ios::end);

		if (movielist.tellg() == 0)
		{
			movielist.close();
			remove(movieListPath.c_str());
			cout << "Database is empty, you need to add some movies." << endl;
		}
		else
		{
			movielist.seekg(0, ios::beg);
			cout << "Movies in database: " << endl;
			cout << movielist.rdbuf();
		}
	}
	movielist.close();
}

void FileName::deleteMovieFile() {
	if (remove(getFinalName().c_str()) != 0)
	{
		perror("Error while trying to delete the file!");
	}
	else
	{
		movielist.open(movieListPath, ios::in);

		if (movielist.is_open())
		{
			ofstream temp("temp.txt", ios::out);

			while (getline(movielist, line))
			{
				if (line != getTitle())
				{
					temp << line << endl;
				}
			}

			movielist.close();
			temp.close();
		}

		try {
			if (remove(movieListPath.c_str())) {
				throw "Error occurred while trying to remove the file.";
			}

			if (rename("temp.txt", movieListPath.c_str())) {
				throw "Error occurred while trying to swap the files.";
			}
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
		cout << "File deleted successfully." << endl;
	}
}

void FileName::searchForActor(string actor) {
	actor = "(Actor) " + actor;
	movielist.open(movieListPath, ios::in);

	if (movielist.is_open())
	{
		cout << "*Search results*" << endl;
		while (getline(movielist, line))
		{
			setTitle(line);
			moviefile.open(getFinalName().c_str(), ios::in);

			if (moviefile.is_open())
			{
				while (getline(moviefile, line))
				{
					if (line == actor)
					{
						cout << "Found actor in: " << getTitle() << endl;
					}
				}

				moviefile.close();
			}
			else
			{
				cout << "Movie file for " << getTitle() << " does not exist!" << endl;
			}
		}
		movielist.close();
	}
	else
	{
		cout << "No movies in database!" << endl;
	}
}