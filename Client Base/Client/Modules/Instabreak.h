#pragma once
#include "../../Other/Module.h"

class Instabreak : public Module {
public:
	Instabreak() : Module::Module("Instabreak", "World", "Instantly destroy blocks") {};
	void onStartDestroyBlock(GameMode* GM, Vec3_i* blockPos, uint8_t blockFace);
};