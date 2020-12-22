#include "Instabreak.h"

void Instabreak::onStartDestroyBlock(GameMode* GM, Vec3_i* blockPos, uint8_t blockFace) {
	GM->destroyBlock(blockPos, blockFace);
}