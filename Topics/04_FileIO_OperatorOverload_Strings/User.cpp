
#include "User.h"

#include <string>
using namespace std;

#include <ostream>
#include <istream>

User::User(string _firstName, string _lastName, int _age, string _ssn, string _tagLine)
{
	firstName = _firstName;
	lastName = _lastName;
	age = _age;
	ssn = _ssn;
	tagLine = _tagLine;
}

string User::getFirstName()
{
	return firstName;
}

string User::getLastName()
{
	return lastName;
}

int User::getAge()
{
	return age;
}

string User::getSSN()
{
	return ssn;
}

string User::getTagLine()
{
	return tagLine;
}

void User::setAge(int newAge)
{
	age = newAge;
}

void User::setTagLine(std::string newTagLine)
{
	tagLine = newTagLine;
}



ostream & operator<<(ostream & os, User & user)
{
	os << user.getLastName() << " " << user.getFirstName() << " " << user.getAge()
	   << " " << user.getSSN() << user.getTagLine() << endl;
	return os;
}

istream & operator>>(istream & is, User & user)
{
	char tag[256];

	is >> user.lastName >> user.firstName >> user.age >> user.ssn;
	is.getline(tag,256);
	user.tagLine = tag;

	return is;

}
