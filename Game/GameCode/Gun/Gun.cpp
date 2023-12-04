#include "stdafx.h"
#include "Gun.h"

#include "GameCode/GameCode.h"
Gun::Gun()
{
	S_Gun.P_GunSight = NewGO<GunSight>(0, "gunsight");
}
Gun::~Gun()
{
	DeleteGO(S_Gun.P_GunSight);
}
void Gun::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && !S_GunData.M_CoolDownFlag)
	{
		NewGO<Bullet>(0,"bullet");
		NewGO<GunSound>(0, "gunsound");
		S_GunData.M_CoolDownFlag = true;
	}else {
		if (S_GunData.M_CoolDownFlag)
		{
			S_GunData.M_CoolDownTime++;
			if (S_GunData.M_CoolDownTime >= S_GunData.M_CoolDownTimeFixed)
			{
				S_GunData.M_CoolDownFlag = false;
				S_GunData.M_CoolDownTime = 0;
			}
		}
	}
}