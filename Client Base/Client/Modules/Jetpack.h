#pragma once
#include "../../Other/Module.h"

class Jetpack : public Module {
public:
	Jetpack() : Module::Module("Jetpack", "Boost directory forwards when holding the desired key (Default: F)", 0x46) {
		this->isEnabled = true;
	};
	void onTick();
private:
	float speed = 1.0f;
	bool modified = false;
};