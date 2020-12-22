#pragma once
#include "../../Other/Module.h"

class AirJump : public Module {
public:
	AirJump() : Module::Module("AirJump", "Movement", "Jump in the air") {};
	void onGmTick();
};