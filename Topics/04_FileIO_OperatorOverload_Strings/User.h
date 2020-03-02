#ifndef USER_H_
#define USER_H_

#include <ostream>
#include <istream>

#include <string>

class User {

	// Make the "operator>>" a friend so the function can get access to private parts
	friend std::istream & operator>>(std::istream & os, User & user);

private:
	std::string firstName;
	std::string lastName;
	int age;
	std::string ssn;
	std::string tagLine;

public:

	// Note the default argument values
	User(std::string first="", std::string last="", int age=0, std::string ssn="", std::string tagLine="");

	// Getters
	std::string getFirstName();
	std::string getLastName();
	int getAge();
	std::string getSSN();
	std::string getTagLine();

	// Two setters ... just for demo
	void setAge(int newAge);
	void setTagLine(std::string newTagLine);

};

// Stream operator functions
std::ostream & operator<<(std::ostream & os, User & user);
std::istream & operator>>(std::istream & os, User & user);

#endif
