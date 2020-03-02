#include <iostream>
using namespace std;

#include "String.h"

int main() {

	String test("Hello World");
	
	cout << test.getCString() << " Length:" << test.getLength() << endl;

	String b("Wowser");
	test.set(b);

	cout << test.getCString() << " Length:" << test.getLength() << endl;

	test.setCharAt(1,'i');
	cout << "'" << test.getCharAt(1) << "' " << test.getCString() << endl;

	test.append("There");
	cout << test.getCString() << " Length:" << test.getLength() << endl; 

	int i = test.getIndexOf("hep");
	cout << i << endl;

}