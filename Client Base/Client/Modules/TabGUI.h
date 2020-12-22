#pragma once
#include "../../Other/Module.h"

class TabGUI : public Module {
public:
	TabGUI() : Module::Module("TabGUI", "Visuals", "Manage Modules via Arrow Keys") {
		this->isEnabled = true;
	};
	void onRender();
	void onKey(uint64_t key, bool isDown);
private:
	int currentCategory = 0, currentModule = 0;
	bool selectedCategory = false, selectedModule = 0;
};