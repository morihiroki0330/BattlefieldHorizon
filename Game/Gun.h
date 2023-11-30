#pragma once
class GunSight;
class GunSound;
struct GunComponent
{
	GunSight* P_GunSight;
	GunSound* P_GunSound;
};
class Gun : public IGameObject
{
public:
	Gun();
	~Gun();
	void Update();
private:
	GunComponent M_Gun;

	bool M_CoolDownFlag = false;

	int M_CoolDownTime = 0;
	int M_CoolDownTimeFixed = 30;

	bool M_Player = false;
	bool M_Enemy = false;
};

