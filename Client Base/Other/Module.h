#pragma once
#include "../SDK/Minecraft.h"

class Module {
public:
	std::string name, category, description;
	uint64_t key;
	bool isEnabled = false, wasEnabled = false;
	Module(std::string name, std::string category, std::string description, uint64_t key = NULL);
	
	void onBaseTick();
	virtual void onLoop() {};
	virtual void onTick() {};
	virtual void onEnable() {};
	virtual void onDisable() {};

	virtual void onRender() {};
	virtual void onKey(uint64_t key, bool isDown) {};
};

class Hook {
public:
	virtual void Install() {};
};