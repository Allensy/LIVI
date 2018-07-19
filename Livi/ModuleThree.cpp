#include "stdafx.h"
#include "ModuleThree.h"


ModuleThree::ModuleThree():Module("ModuleThree",3)
{
}


ModuleThree::~ModuleThree()
{
}

bool ModuleThree::Start()
{
	//std::cout << "ModuleThree Started" << std::endl;
	return true;
}

bool ModuleThree::Stop()
{
	std::cout << "ModuleThree Stopped" << std::endl;
	return true;
}
