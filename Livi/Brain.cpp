#include "stdafx.h"
#include "Brain.h"
#include <algorithm>

bool Brain::bufferChanged;
std::string Brain::buffer;

Brain::Brain()
{
	this->details.m_name = "Livi";
	this->details.m_id = 1;
	// Initialize Statics
	Brain::bufferChanged = false;

	// Initialize Base Modules
	AddBaseModule(new TextListener);
	AddBaseModule(new TextAnalyzer);
}

Brain::~Brain()
{
	StopAllModules();
}


bool Brain::AddModule(Module * module) {
	this->Modules.push_back(module);
	return true;
}

bool Brain::AddBaseModule(Module * module) {
	this->BaseModules.push_back(module);
	return true;
}

// Starts each base module in a new thread
void Brain::StartBaseModules()
{
	for (int i = 0; i < this->BaseModules.size(); i++)
	{
		this->Threads.push_back(std::thread([](Module * mod) {mod->Start(); }, this->BaseModules[i]));
	}
}

// These functions use "Algorithm" library, they recieve two Iterators (Begin,End) and a Lambda function [you can also use an Object Function] to 
// start a certain operation on all elements of the Brain's Vector.
// Example - this calls the "Start()" function of all modules we will ever have
void Brain::StartAllModules() {
	std::for_each(this->Modules.begin(), this->Modules.end(),
		[](Module * mod) { mod->Start(); });
}

// This calls the "Stop()" function of all modules we will ever have
void Brain::StopAllModules()
{
	std::for_each(this->Modules.begin(), this->Modules.end(),
		[](Module * mod) { mod->Stop(); });
}

// Brain start command, this is where the brain actually works.
void Brain::Start()
{
	int counter = 0;
	std::cout << "Artificial Intelligence Started\nName : " << this->details.m_name << "\n" << "Identification: " << this->details.m_id << std::endl;
	StartBaseModules();
	StartAllModules();
	while (true) {
		// Remind us that Brain works on the main thread, and does not stop because TextListener is working.
		if (counter == 50) {
			std::cout << "(Brain) : I am working.. " << Brain::buffer << std::endl;
			counter = 0;
		}
		// Making sure Brain wont spam the CMD
		counter++;
		// TextListener got a text and moved it to Brain to analyze and answer
		if (bufferChanged) {
			std::cout << "(Brain) : Got your Message: " << Brain::buffer << std::endl;
			// Send text to analyzer and return an answer, Analyzer is very weak and we will replace him with a sophisticated one.
			std::cout << "(Brain) : My Answer: " << dynamic_cast<TextAnalyzer&>(*this->BaseModules[TEXTANALYZER]).GetAnswer(Brain::buffer) << std::endl;
			Brain::bufferChanged = false;
		}
		Sleep(100);
	}
}



