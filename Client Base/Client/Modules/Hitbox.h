#pragma once
#include "../../Other/Module.h"

class Hitbox : public Module {
public:
	Hitbox() : Module::Module("Hitbox", "Enlarge Enemy Hitboxes") {
		this->isEnabled = true;
	}
	void onTick();
};