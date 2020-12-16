#pragma once
#include "../Other/Utils.h"

#include "Classes/ClientInstance.h"

class Minecraft {
private:
	static ClientInstance* CachedInstance;
public:
	static UINT64 ModuleBase() {
		return (UINT64)GetModuleHandle(NULL);
	}
	static void SetClientInstance(ClientInstance* obj) {
		if (obj != nullptr) CachedInstance = obj;
	}
	static ClientInstance* ClientInstance() {
		return CachedInstance;
	}
};