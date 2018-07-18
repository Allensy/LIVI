#include "stdafx.h"
#include "Brain.h"
#include <algorithm>


Brain::Brain()
{
	this->details.m_name = "Livi";
	this->details.m_id = 1;
	std::cout << "Brain created\nName : " << this->details.m_name << "\n" << "Identification: " << this->details.m_id << std::endl;
}

Brain::Brain(std::string name, int id)
{
	this->details.m_name = name;
	this->details.m_id = id;
}

Brain::Brain(Brain & other)
{
	this->details.m_name = other.details.m_name;
	this->details.m_id = other.details.m_id;
}


Brain::~Brain()
{
}

bool Brain::AddModule(Module * module) {
	this->Modules.push_back(module);
	return true;
}

void Brain::StartAllModules() {
	std::for_each(this->Modules.begin(), this->Modules.end(),
		[](Module * mod) { mod->Start(); });
}

void Brain::StopAllModules()
{
	std::for_each(this->Modules.begin(), this->Modules.end(),
		[](Module * mod) { mod->Stop(); });
}

