#include "TestModule.h"

void TestModule::onGmTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	if (Player != nullptr) {
		MultiPlayerLevel* curr = Player->MultiPlayerLevel;
		size_t size = curr->getListSize();
		if (size > 0 && size <= 5000) {
			for (size_t I = 0; I < size; I++) {
				Actor* currPlayer = curr->get(I);
				if (currPlayer != nullptr && currPlayer != Player) {
					currPlayer->setNameTagVisible(true);
				}
			}
		}
	}
}