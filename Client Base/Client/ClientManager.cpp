#include "ClientManager.h"
#include "../Other/Module.h"

std::vector<Hook*> Hooks;
std::vector<Module*> Modules;

#include "Hooks/ClientInstance.h"
#include "Hooks/KeyItem.h"

ClientInstance* Minecraft::CachedInstance = nullptr; //Resolve error on compile

void ClientManager::InitHooks() {

	if (MH_Initialize() == MH_OK) {
		Hooks.push_back(new ClientInstance_Hook());
		Hooks.push_back(new KeyItem());
	}

	Utils::DebugLogOutput("Initializing Hooks...");

	for (int I = 0; I < Hooks.size(); I++) { //Initialize the hooks
		Hooks.at(I)->Install();
	}
}

#include "Modules/Hitbox.h"
#include "Modules/AirJump.h"
#include "Modules/Jetpack.h"

void ClientManager::InitModules() {
	Modules.push_back(new Hitbox());
	Modules.push_back(new AirJump());
	Modules.push_back(new Jetpack());

	for (;;) {
		for (int I = 0; I < Modules.size(); I++) { //Loop Modules
			Modules.at(I)->onBaseTick();
		}
	}
}