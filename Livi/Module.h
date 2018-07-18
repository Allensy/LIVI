/*
This is an Interface class, It can not be instantiated alone, only by calling a derived class.
Module requires all derived classes to implement and override the functions:
- Start()
- Stop()
We will eventually add more functions that must be in every module that "Brain" uses.

Every module has a Name, and and Identification Number (add more variables later)
*/


#pragma once
#include <string>
class Module {
protected:
	std::string m_name;
	int m_id;
public:
	Module(std::string name, int id){
		this->m_name = name;
		this->m_id = id;
	}
	// Interface Functions
	virtual bool Start() = 0;
	virtual bool Stop() = 0;

	// Regular Functions
	void SetModuleName(std::string name) { this->m_name = name; }
	void SetModuleId(int id) { this->m_id = id; }
	std::string GetModuleName() { return this->m_name; }
	int GetModuleId() { return this->m_id; }
};
