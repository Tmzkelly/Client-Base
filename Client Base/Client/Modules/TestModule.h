#pragma once
#include "../../Other/Module.h"

class TestModule : public Module {
public:
	TestModule() : Module::Module("Test Module", "Other", "Testing") {};
	void onGmTick();
};