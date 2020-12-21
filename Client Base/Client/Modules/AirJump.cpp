#include "AirJump.h"

void AirJump::onTick() {
	if (Minecraft::ClientInstance()->LocalPlayer() != nullptr) {
		Minecraft::ClientInstance()->LocalPlayer()->onGround = true;
	}
}