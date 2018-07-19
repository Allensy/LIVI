#pragma once
#include "Module.h"
#include <set>
class TextAnalyzer :
	public Module
{
private:
	std::set<std::string> Greetings = { "Hello","Hi","Hey" };
	std::set<std::string> Questions = { "How","Where","When" };
	std::set<std::string> Commands = { "Call","Play","Find" };
public:
	TextAnalyzer();
	~TextAnalyzer();

	// Interface Overriden Functions
	bool Start();
	bool Stop();
	std::string GetAnswer(std::string line);
};

