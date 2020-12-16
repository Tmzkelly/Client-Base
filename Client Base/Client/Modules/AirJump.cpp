#include "AirJump.h"

void AirJump::onTick() {
	if (Minecraft::ClientInstance()->LocalPlayer() != nullptr) {
		Minecraft::ClientInstance()->LocalPlayer()->SetOnGroundState(true);
	}
}

void AirJump::onEnable() {
	Utils::DebugLogOutput("Enabled AirJump!");
}

void AirJump::onDisable() {
	Utils::DebugLogOutput("Disabled AirJump!");
}