#pragma once
#include "Module.h"
class ModuleThree :
	public Module
{
public:
	ModuleThree();
	~ModuleThree();

	// Interface Overriden Functions
	bool Start();
	bool Stop();
};

