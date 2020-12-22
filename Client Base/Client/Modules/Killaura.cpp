#include "Killaura.h"

void Killaura::onGmTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	MultiPlayerLevel* Level = Player->MultiPlayerLevel;
	GameMode* GM = Minecraft::GameMode();
	if (Player != nullptr && GM != nullptr && Level != nullptr) {
		Vec3 myPos = *Player->getPos();
		size_t entListSize = Level->getListSize();
		if (entListSize > 0 && entListSize <= 5000) {
			for (size_t I = 0; I < entListSize; I++) {
				Actor* currEnt = Level->get(I);
				float distance = currEnt->getPos()->distance(myPos);
				if (currEnt != nullptr && currEnt != Player && distance <= 12.f){
					bool isFriend = false;
					for (auto Friend : Minecraft::Friends) {
						if (currEnt->getFormattedNameTag() == Friend) isFriend = true;
					}
					if (!isFriend) {
						GM->attack(currEnt);
						Player->swing();
					}
				}
			}
		}
	}
}