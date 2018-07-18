#include "stdafx.h"
#include "ModuleTwo.h"


ModuleTwo::ModuleTwo():Module("ModuleTwo", 2)
{
}


ModuleTwo::~ModuleTwo()
{
}

bool ModuleTwo::Start()
{
	std::cout << "ModuleTwo Started" << std::endl;
	return true;
}

bool ModuleTwo::Stop()
{
	std::cout << "ModuleTwo Stopped" << std::endl;
	return true;
}
