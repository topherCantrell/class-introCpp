#include <iostream>
using namespace std;

#include "MadLib.h"

void main() {

	// Or use the command line arguments
	MadLib mad("c:/cpp/day5/AliensInClass.txt");

	// Prompt the user fo inputs
	for(int x=0;x<mad.getNumberOfInputs();++x) {
		string s = mad.getInputPrompt(x);
		cout << s;
		cin >> s;
		mad.setInputValue(x,s);
	}

	// Some space
	cout << endl << endl;

	// Print the story
	mad.printStory();

	system("pause");

}