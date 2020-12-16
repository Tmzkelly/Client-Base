#pragma once
#include "../SDK/Minecraft.h"

class Module {
public:
	std::string name, description;
	uint64_t key;
	bool isEnabled = false, wasEnabled = false;
	Module(std::string name, std::string description, uint64_t key = NULL);
	
	virtual void onBaseTick();
	virtual void onTick() {};
	virtual void onEnable() {};
	virtual void onDisable() {};
};

class Hook {
public:
	virtual void Install() {};
};