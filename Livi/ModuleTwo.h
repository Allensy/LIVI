/*
Temporary "Derived Module" example
*/

#pragma once
#include "Module.h"
class ModuleTwo :
	public Module
{
public:
	ModuleTwo();
	~ModuleTwo();

	// Interface Overriden Functions
	bool Start();
	bool Stop();
};

