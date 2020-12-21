#pragma once
#include "../../Other/Module.h"

class AirJump : public Module {
public:
	AirJump() : Module::Module("AirJump", "Jump in the air") {
		this->isEnabled = true;
	};
	void onTick();
};