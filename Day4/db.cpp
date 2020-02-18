
#include <iostream>
using namespace std;

#include <fstream>

#include "User.h"
#include "UserDB.h"

void main() {

	UserDB db;

	int inp;
	fstream myDbFile;
	string filename;
	User newUser;


	while(true) {
		cout << "Commands:" << endl 
			<< " 1 fname (read from fname)" << endl 
			<< " 2 fname (write to fname)" << endl 
			<< " 3 last first age ssn tag (create new)" << endl 
			<< " 4 (print db)" << endl;

		cin >> inp;

		switch(inp) {
		case 1: // Read from file

			cin >> filename;			
			myDbFile.open(filename, fstream::in);
			myDbFile >> db;
			myDbFile.close();
			break;

		case 2: // Write to file

			cin >> filename;
			myDbFile.open(filename, fstream::out);
			myDbFile << db;
			myDbFile.flush();
			myDbFile.close();
			break;

		case 3: // Create new user

			cin >> newUser;
			db.addUser(newUser);
			break;

		case 4: // Print DB

			cout << db;
			break;

		default:
			return;

		}
	}
	
}