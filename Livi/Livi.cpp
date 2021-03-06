/*
Project Name : Livi
Authors : Allen Aharon Jacobson, Yuval Lavie
Summary:
Livi is an Artificial Intelligence designed for casual living, its a "Smart Automaton".
Livi wil be made of a Central part - "Brain" and lots of modules.
*/
#include "stdafx.h"


int main()
{
	// Brain
	Brain brain;
#pragma region MODULES
	// ModuleOne ("Voice Recognition")
	ModuleOne mdOne;
	brain.AddModule(&mdOne);

	// ModuleTwo ("Text Recognition")
	ModuleTwo mdTwo;
	brain.AddModule(&mdTwo);

	// ModuleThree ("Database Manager")
	ModuleThree mdThree;
	brain.AddModule(&mdThree);
#pragma endregion

	brain.StartAllModules();
	brain.StopAllModules();



	system("pause");
    return 0;
}

