#include "ClientManager.h"
#include "../Other/Module.h"

std::vector<Hook*> Hooks;
std::vector<Module*> Modules;

#include "Hooks/ClientInstance.h"

ClientInstance* Minecraft::CachedInstance = nullptr; //Resolve error on compile

void ClientManager::InitHooks() {

	if (MH_Initialize() == MH_OK) {
		Hooks.push_back(new ClientInstance_Hook());
	}

	Utils::DebugLogOutput("Initializing Hooks...");

	for (int I = 0; I < Hooks.size(); I++) { //Initialize the hooks
		Hooks.at(I)->Install();
	}
}

#include "Modules/AirJump.h"

void ClientManager::InitModules() {
	Modules.push_back(new AirJump());

	for (;;) {
		for (int I = 0; I < Modules.size(); I++) { //Loop Modules
			Modules.at(I)->onBaseTick();
		}
	}
}