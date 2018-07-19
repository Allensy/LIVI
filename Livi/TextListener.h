#pragma once
#include "Module.h"
class TextListener :
	public Module
{
private:
	bool Work;
	std::string Line;
public:
	TextListener();
	~TextListener();

	// Interface Overriden Functions
	bool Start();
	bool Stop();


};

