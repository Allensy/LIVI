#include "stdafx.h"
#include "TextAnalyzer.h"


TextAnalyzer::TextAnalyzer() :Module("TextAnalyzer", 2)
{
}


TextAnalyzer::~TextAnalyzer()
{
}

bool TextAnalyzer::Start()
{
	//std::cout << "Text Analyzer started" << std::endl;
	return true;
}

bool TextAnalyzer::Stop()
{
	return false;
}

std::string TextAnalyzer::GetAnswer(std::string line)
{
	if (Greetings.find(line) != Greetings.end())
		return std::string("It's a greeting");
	if (Questions.find(line) != Questions.end())
		return std::string("It's a Question!");
	if (Commands.find(line) != Commands.end())
		return std::string("It's a Command");
	else
		return std::string("Could not figure out what you were saying!\n Try: Hey,Hello,Hi or How,When,Where or Call,Play,Find");
	

}
