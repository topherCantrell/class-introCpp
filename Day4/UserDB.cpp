#include "UserDB.h"

#include <ostream>
#include <istream>
#include "User.h"
using namespace std;

UserDB::UserDB()
{
	users = new User[100];
	numberOfUsers = 0;
}

int UserDB::getNumberOfUsers()
{
	return numberOfUsers;
}

User UserDB::getUserAt(int index)
{
	return users[index];
}

void UserDB::addUser(User u)
{
	users[numberOfUsers] = u;
	++numberOfUsers;
}


ostream& operator<<(ostream& os, UserDB& db)
{
	os << db.getNumberOfUsers() << endl;
	for(int x=0;x<db.getNumberOfUsers();++x) {
		os << db.getUserAt(x);
	}
	return os;
}

istream& operator>>(istream& is, UserDB& db)
{	
	int x;
	is >> x;
	for(int y=0;y<x;++y) {
		User u;
		is >> u;
		db.addUser(u);
	}	
	return is;
}
