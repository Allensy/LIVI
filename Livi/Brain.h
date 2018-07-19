/*
Brain - The controller of the Artificial Intelligence
the brain controls everything, it holds an array of Modules, each having its own job.
The brain will eventually decide which module starts, stops, has permissions, can access the database, can talk to the user. and more

The brain is the centerpiece of this project, it talks to each module, even those who run on different threads.
Example usage of talking to the brain.
(1) Brain starts, starting the base modules TextListener and TextAnalyzer with new threads.
(2) TextListener waits for input from the user, receives it and sends it back to the brain (Just like ears would word)
(3) the Brain then sends that input to the TextAnalyzer, which anaylzes the text and returns the brain with an answer
(4) the Brain then answers the user.
*/

#pragma once
#include "Module.h"
// Base Modules
#include "TextListener.h"
#include "TextAnalyzer.h"
// Others
#include <vector>
#include <thread>

enum {TEXTLISTENER,TEXTANALYZER};
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
	// Polymorphic Vectors of Modules
	std::vector<Module*> Modules;
	// These are Basic Modules that need to ALWAYS run in a separate thread, like "Listeners"
	std::vector<Module*> BaseModules;
	// Thread vector for base modules, so that when they run, they wont interfer with the Brain's normal activities.
	std::vector<std::thread> Threads;
	
public:
	// ---------------------------------------
	// # There variables help transfer data from the "Listener" part to the brain, and from the brain to the analyzer.
	static std::string buffer;
	static bool bufferChanged;
	// ---------------------------------------

	// Default Constructor
	Brain();
	// Destructor
	~Brain();

#pragma region Functions

	// Base Modules
	bool AddBaseModule(Module * module);

	void StartBaseModules();

	// Add a module to the module array, Should return a boolean of success, we will cover that later when we can figure out if a module started or failed.
	bool AddModule(Module * module);
	// Start All Modules
	void StartAllModules();
	// Stop All Modules
	void StopAllModules();

	void Start();

#pragma endregion

};

