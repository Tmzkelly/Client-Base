#pragma once
#include "../../Other/Module.h"

class Jetpack : public Module {
public:
	Jetpack() : Module::Module("Jetpack", "Movement", "Boost directory forwards when holding the desired key (Default: F)", 0x46) {};
	void onLoop();
	void onTick();
private:
	float speed = 1.0f;
	bool modified = false;
};