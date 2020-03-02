
#include "String.h"

#include <cstring>

String::String() : data(0), length(0)
{
	// data=0;
	// length=0;
}

String::String(char* s)
{
	length = strlen(s);
	data = new char[length+1];
	strcpy(data,s);
}

char* String::getCString()
{
	return data;
}

int String::getLength()
{
	return length;
}

void String::set(String other)
{
	if(data!=0) {
		delete [] data;
	}
	length = other.length;
	data = new char[length+1];
	strcpy(data,other.data);
}

char String::getCharAt(int index)
{
	if(index<0 || index>=length) {
		return 0;
	}
	return data[index];
}

void String::setCharAt(int index, char n)
{
	if(index<0 || index>=length) {
		return;
	}
	data[index] = n;
}

void String::append(String other)
{
	// Remember the old string
	char* old = data;
	int oldLength = length;

	// Make space for a bigger string ... old+new
	length = length + other.getLength();
	data = new char[length + 1];

	// Copy the old string into the new space and delete the old space
	if(old!=0) {
		strcpy(data,old);
		delete [] old;
	}
	
	// Copy the new string into the new space at the end
	strcpy(&data[oldLength],other.data);
}

int String::getIndexOf(String other)
{
	char* find=strstr(data,other.data);
	if(find==0) {
		return 0;
	}

	return find-data;
}
