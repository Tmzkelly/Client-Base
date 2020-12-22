#pragma once
#include "../../Other/Module.h"

class Hitbox : public Module {
public:
	Hitbox() : Module::Module("Hitbox", "Combat", "Enlarge Enemy Hitboxes") {}
	void onGmTick();
	void onDisable();
};