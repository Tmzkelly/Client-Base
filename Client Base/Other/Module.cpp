#include "Module.h"

Module::Module(std::string name, std::string description, uint64_t key) {
	this->name = name;
	this->description = description;
	this->key = key;
}

void Module::onBaseTick() {
	if (wasEnabled != isEnabled) {
		if (isEnabled) {
			onEnable();
		}
		else {
			onDisable();
		}
		wasEnabled = isEnabled;
	}
	if (isEnabled) onTick();
}