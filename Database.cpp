#include "Database.h"

Database::Database() {}

Database::~Database() {}

void Database::AddMovie() {
    cout << "specify movie title: ";
    getline(cin, sTemp);
    fn.setTitle(sTemp);

    ifstream check(fn.getFinalName().c_str(), ios::in);
    if (!check.good())
    {
        check.close();
        cout << "specify release year in [YYYY] format: ";
        cin >> nTemp;
        mi.setYear(nTemp);

        while (mi.getYear() < 1877) {
            cout << "Are you sure about that? First movie ever was made in 1877." << endl;
            cout << "specify release year in [YYYY] format: ";
            cin >> nTemp;
            mi.setYear(nTemp);
        }

        cout << "How many staff you want to add?" << endl;
        cin >> nTemp;
        char staffchoice;
        for (int i = 0; i < nTemp; i++)
        {
            cout << "Staff type: 0-director, 1-actor" << endl;
            cin >> staffchoice;
            cin.ignore();

            if (staffchoice == '0')
            {
                cout << "Enter director's name: ";
                getline(cin, sTemp);
                tempDirector = new Director();
                tempDirector->setName(sTemp);
                mi.setStaff(tempDirector);
            }
            if (staffchoice == '1')
            {
                cout << "Enter actor's name: ";
                getline(cin, sTemp);
                tempActor = new Actor();
                tempActor->setName(sTemp);
                mi.setStaff(tempActor);
            }
        }

        cout << "What about a short description of a movie? (0- no, 1- yes)" << endl;
        char descchoice;
        cin >> descchoice;
        cin.ignore();

        if (descchoice == '1')
        {
            cout << "type in your description:" << endl;
            getline(cin, sTemp);
            mi.setDesc(sTemp);
        }
        else if (descchoice == '0')
        {
            cout << "file left without description" << endl;
        }
        else
        {
            cout << "So uncivilized. No description chosen.";
        }

        fn.createNewMovie(mi);
        mi.clearStaff();
    }
    else {
        cout << "The movie is already in database." << endl;
    }
}

void Database::ViewMovieInfo() {
	cout << "specify movie title: ";
	getline(cin, sTemp);
	fn.setTitle(sTemp);
	fn.readMovieDetails();
}

void Database::DeleteMovie() {
	cout << "specify movie title to delete: ";
	getline(cin, sTemp);
	fn.setTitle(sTemp);
	fn.deleteMovieFile();
}

void Database::ViewMovieList() {
	fn.readMovieList();
}

void Database::SearchMoviesByActor() {
	cout << "specify actor to search by: ";
	getline(cin, sTemp);
	fn.searchForActor(sTemp);
}
