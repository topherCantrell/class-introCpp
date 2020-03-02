#include "MadLib.h"
#include <fstream>
#include <iostream>

using namespace std;

MadLib::MadLib(string storyFileName)
{
	// Open the file
	fstream fs;
	fs.open(storyFileName,fstream::in);

	// Read in the inputs
	string s;
	while(!fs.eof()) {

		getline(fs,s);
		if(s.size()==0 || s[0]!='%') continue;
		if(s=="%") break;

		int secondPercent = s.find('%',1);
		string key = s.substr(0,secondPercent+1);
		string prompt = s.substr(secondPercent+2);

		keys.push_back(key);		
		prompts.push_back(prompt);
	}

	// Read in the story lines
	while(!fs.eof()) {
		getline(fs,s);
		storyLines.push_back(s);
	}

	fs.close();
}

int MadLib::getNumberOfInputs() {
	return keys.size();
}

string MadLib::getInputPrompt(int index) {
	return prompts[index];
}

void MadLib::setInputValue(int index, std::string value) {
	string key = keys[index];
	values[key] = value;
}

string MadLib::getInputValue(std::string key) {
	string s = values[key];
	if(s.length()==0) {
		s = "??";
	}
	return s;
}

void MadLib::printStory() {

	for(int x=0;x<storyLines.size();++x) {
		string s = storyLines[x];

		while(true) {
			int per = s.find('%');
			if(per<0) break;
			int per2 = s.find('%',per+1);
			int keyLength = per2-per;
			string first = s.substr(0,per);
			string key = s.substr(per,keyLength+1);
			string second = s.substr(per2+1);
			s = first+getInputValue(key)+second;
		}
				
		cout << s << endl;
	}
}
