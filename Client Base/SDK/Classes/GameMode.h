#pragma once

class GameMode {
public:
	LocalPlayer* Player; //0x0008

	virtual void Destructor();
	virtual void startDestroyBlock(Vec3_i*, UCHAR, bool);
	virtual void destroyBlock(Vec3_i*, UCHAR);
	virtual void continueDestroyBlock(Vec3_i*, UCHAR, bool);
	virtual void stopDestroyBlock(Vec3_i*);
	virtual void startBuildBlock(Vec3_i*, UCHAR);
	virtual void buildBlock(Vec3_i*, UCHAR);
	virtual void continueBuildBlock(Vec3_i*, UCHAR);
	virtual void stopBuildBlock(void);
	virtual void tick(void);
	virtual float getPickRange();
	virtual void useItem();
	virtual void useItemOn();
	virtual void interact(Actor*, Vec3*);
	virtual void attack(Actor*);
	virtual void releaseUsingItem();
};