#include "Jetpack.h"

void Jetpack::onLoop() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	MinecraftGame* mcGame = Minecraft::ClientInstance()->MinecraftGame();
	if (Utils::usingKey(this->key)) {
		if (Player != nullptr && mcGame != nullptr && mcGame->canUseKeys()) {
			this->isEnabled = true;
		}
		else {
			if (this->isEnabled) this->isEnabled = false;
		}
	}
	else {
		if(this->isEnabled) this->isEnabled = false;
	}
}

void Jetpack::onTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	if (Player != nullptr) {
		Vec2 currRot = Player->bodyRot;
		Vec2 angles = Vec2((currRot.x) * -(PI / 180.f), (currRot.y + 90.0f) * (PI / 180.f));
		Player->velocity = Vec3(cos(angles.y) * cos(angles.x) * speed, sin(angles.x) * speed, sin(angles.y) * cos(angles.x) * speed);
	}
}