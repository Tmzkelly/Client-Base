#pragma once
#include "MultiPlayerLevel.h"

class LocalPlayer {
public:
	class MultiPlayerLevel* MultiPlayerLevel() {
		if (this != nullptr) {
			return *reinterpret_cast<class MultiPlayerLevel**>(reinterpret_cast<__int64>(this) + 0x358);
		}
		else {
			return nullptr;
		}
	}

	void SetOnGroundState(bool state) {
		if (this != nullptr) {
			*(bool*)(reinterpret_cast<uintptr_t>(this) + 0x1C0) = state;
		}
	}

	void SetStepHeight(float value) {
		if (this != nullptr) {
			*(float*)(reinterpret_cast<uintptr_t>(this) + 0x220) = value; //Default = 0.5625
		}
	}

	void ModifyCollision(float width, float height) {
		if (this != nullptr) {
			float* widthAddr = (float*)(reinterpret_cast<uintptr_t>(this) + 0x4B4);
			float* heightAddr = (float*)(reinterpret_cast<uintptr_t>(this) + 0x4B8);
			*widthAddr = width;
			*heightAddr = height;
		}
	}
};