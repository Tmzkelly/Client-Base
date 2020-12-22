#pragma once
#include "../../Other/Module.h"

class Killaura : public Module {
public:
	Killaura() : Module::Module("Killaura", "Combat", "Automatically attack nearby entities") {};
	void onGmTick();
};