#ifndef USER_DB_H_
#define USER_DB_H_

#include "User.h"
#include <ostream>
#include <istream>

class UserDB {

private:

	User* users; // Dynamic memory here ... a maximum
	int numberOfUsers; // Current number of users

public:

	UserDB();

	int getNumberOfUsers();
	User getUserAt(int index);
	void addUser(User u);

};

// No need for "friends" here.
std::ostream& operator<<(std::ostream& os, UserDB& db);
std::istream& operator>>(std::istream& is, UserDB& db);

#endif