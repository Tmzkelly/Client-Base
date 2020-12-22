#include "Jesus.h"

void Jesus::onGmTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	if (Player != nullptr && Player->isInWater() || Player->isInLava()) {
		Player->velocity.y = 0.25f;
	}
}