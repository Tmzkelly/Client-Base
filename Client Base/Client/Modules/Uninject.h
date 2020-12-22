#pragma once
#include "../../Other/Module.h"

class Uninject : public Module {
public:
	Uninject() : Module::Module("Uninject", "Other", "Uninject the Client from the Game") {};
	void onEnable();
};