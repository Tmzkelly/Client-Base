#pragma once
#include "LocalPlayer.h"

class ClientInstance {
public:
	class LocalPlayer* LocalPlayer() {
		if (this != nullptr) {
			return *reinterpret_cast<class LocalPlayer**>(reinterpret_cast<__int64>(this) + 0x138);
		}
		else {
			return nullptr;
		}
	}
	class MinecraftGame* MinecraftGame() {
		if (this != nullptr) {
			return *reinterpret_cast<class MinecraftGame**>(reinterpret_cast<__int64>(this) + 0x98);
		}
		else {
			return nullptr;
		}
	}
};

class MinecraftGame {
public:
	bool canUseKeys() {
		return *(bool*)(reinterpret_cast<uintptr_t>(this) + 0x260);
	}
};