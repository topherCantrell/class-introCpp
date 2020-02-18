
#ifndef STRING_H_
#define STRING_H_

class String {

private:
	char* data;
	int length;

public:

	String();
	String(char* s);	

	char* getCString();

	int getLength();

	void set(String other);

	char getCharAt(int index);

	void setCharAt(int index, char n);

	void append(String other);

	int getIndexOf(String other);	

	String& operator+(String& other);

	char& operator[](unsigned int i); 

};


#endif
