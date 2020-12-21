#pragma once
#include "MultiPlayerLevel.h"

class Actor {
public:
	char pad_0008[280]; //0x0008
	Vec2 bodyRot; //0x0120
	char pad_0128[152]; //0x0128
	bool onGround; //0x01C0
	char pad_01C1[95]; //0x01C1
	float stepHeight; //0x0220 | Default = 0.5625
	char pad_0224[308]; //0x0224
	class MultiPlayerLevel* MultiPlayerLevel; //0x0358
	char pad_0360[340]; //0x0360
	Vec2 collision; //0x04B4
	char pad_04BC[24]; //0x04BC
	Vec3 velocity; //0x04D4
	char pad_04E0[880]; //0x04E0

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
};