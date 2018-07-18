#pragma once
#include "Module.h"
class ModuleOne :
	public Module
{
public:
	ModuleOne();
	~ModuleOne();

	// Interface Overriden Functions
	bool Start();
	bool Stop();
};

