/*
Project Name : Livi
Authors : Allen Aharon Jacobson, Yuval Lavie
Summary:
Livi is an Artificial Intelligence designed for casual living, its a "Smart Automaton".
Livi wil be made of a Central part - "Brain" and lots of modules.


Explanation:
Brain is the most basic part of the AI, it should potentially control everything.
The brain holds an array of pointers to Modules, each will have a job of its own (Separation of concerns).
Using this design pattern it will be easier to remove,replace,manage modules at more advanced stages of this project
*/
#include "stdafx.h"


int main()
{
	// Brain (The the controller of the AI)
	Brain brain;
#pragma region MODULES

	// Example modules, they do not do anything right now.
	// I create a module, and add it to the brain. from now on the Brain manages them.
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

	// Starting all modules
	brain.StartAllModules();
	// Stopping all modules
	brain.StopAllModules();



	system("pause");
    return 0;
}

