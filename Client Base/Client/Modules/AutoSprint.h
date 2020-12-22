#pragma once
#include "../../Other/Module.h"

class AutoSprint : public Module {
public:
	AutoSprint() : Module::Module("AutoSprint", "Movement", "Automatically sprint forward") {};
	void onGmTick();
};