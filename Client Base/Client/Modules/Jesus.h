#pragma once
#include "../../Other/Module.h"

class Jesus : public Module {
public:
	Jesus() : Module::Module("Jesus", "Movement", "Automatically float above water") {};
	void onGmTick();
};