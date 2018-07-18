#include "stdafx.h"
#include "ModuleOne.h"


ModuleOne::ModuleOne():Module("ModuleOne",1)
{
}


ModuleOne::~ModuleOne()
{
}

bool ModuleOne::Start()
{
	std::cout << "ModuleOne Started" << std::endl;
	return true;
}

bool ModuleOne::Stop()
{
	std::cout << "ModuleOne Stopped" << std::endl;
	return true;
}
