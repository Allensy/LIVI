#include "stdafx.h"
#include "TextListener.h"


TextListener::TextListener():Module("TextListener",4)
{
	this->Work = true;
}


TextListener::~TextListener()
{
}

bool TextListener::Start()
{
	std::cout << "I am listening to you .." << std::endl;
	// Heartbeat
	while (Brain::buffer != "exit") {
		if (Brain::bufferChanged == false) {
			std::getline(std::cin, Brain::buffer);
			std::cout << "Transfering data to brain" << std::endl;
			Brain::bufferChanged = true;
		}
	}
	return true;
}

bool TextListener::Stop()
{
	std::cout << "TextListener Stopped" << std::endl;
	return true;
}
