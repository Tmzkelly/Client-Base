#include "Jetpack.h"

void Jetpack::onTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	MinecraftGame* mcGame = Minecraft::ClientInstance()->MinecraftGame();
	if (Player != nullptr && mcGame != nullptr) {
		if (Utils::usingKey(this->key) && mcGame->canUseKeys()) {
			Utils::DebugLogOutput("!");
			Vec2 currRot = Player->bodyRot;
			Vec2 angles = Vec2((currRot.x) * -(PI / 180.f), (currRot.y + 90.0f) * (PI / 180.f));
			Player->velocity = Vec3(cos(angles.y) * cos(angles.x) * speed, sin(angles.x) * speed, sin(angles.y) * cos(angles.x) * speed);
		}
	}
}