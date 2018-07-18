/*
Brain - The controller of the Artificial Intelligence
the brain controls everything, it holds an array of Modules, each having its own job.
The brain will eventually decide which module starts, stops, has permissions, can access the database, can talk to the user. and more
*/

#pragma once
#include "Module.h"
#include "ModuleOne.h"
#include "ModuleTwo.h"
#include "ModuleThree.h"

#include <vector>
typedef struct DETAILS {
	std::string m_name;
	int m_id;
	int m_version = 1;
}DETAILS;

class Brain
{
private:
	DETAILS details;

	/*
	This "Vector" is a Polymorphic array of the most basic class Module, Module is an Interface and cannot be instantiated by itself.
	only by calling a derived class. each Module must implemented functions "Start" and "Stop" as required by the virtual pure functions 
	in the declarations in Module.h
	*/
	// Polymorphic Vector of Modules
	std::vector<Module*> Modules;

public:
	// Default Constructor
	Brain();
	// Parameretized Constructor
	Brain(std::string name,int id);
	// Copy Constructor
	Brain(Brain & other);

	// Destructor
	~Brain();

#pragma region Functions
	// Add a module to the module array, Should return a boolean of success, we will cover that later when we can figure out if a module started or failed.
	bool AddModule(Module * module);
	// Start All Modules
	void StartAllModules();
	// Stop All Modules
	void StopAllModules();
#pragma endregion

};

