#pragma once

#include <string>
#include <vector>
#include <map>

class MadLib
{

	std::vector<std::string> keys;
	std::vector<std::string> prompts;
	std::vector<std::string> storyLines;
	
	std::map<std::string,std::string> values;

public:

	MadLib(std::string storyFileName);

	~MadLib();

	int getNumberOfInputs();

	std::string getInputPrompt(int index);

	void setInputValue(int index, std::string value);

	std::string getInputValue(std::string key);

	void printStory();

};

