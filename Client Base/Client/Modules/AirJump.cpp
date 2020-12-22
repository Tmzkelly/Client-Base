#include "AirJump.h"

void AirJump::onGmTick() {
	if (Minecraft::ClientInstance()->LocalPlayer() != nullptr) {
		Minecraft::ClientInstance()->LocalPlayer()->onGround = true;
	}
}