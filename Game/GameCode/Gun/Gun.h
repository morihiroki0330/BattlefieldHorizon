#pragma once
#include "DimensionalStorage/StructStorage.h"
class Gun : public IGameObject
{
public:
	Gun();
	~Gun();
	void Update();
private:
	DataGun S_GunData;
	ClassGun S_Gun;
};

