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
	bool AddModule(Module * module);
	void StartAllModules();
	void StopAllModules();
#pragma endregion

};

