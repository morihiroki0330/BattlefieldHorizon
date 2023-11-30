#include "stdafx.h"
#include "Gun.h"

#include "GunSight.h"
#include "GunSound.h"
#include "Bullet.h"
Gun::Gun()
{
	M_Gun.P_GunSight = NewGO<GunSight>(0, "gunsight");
}
Gun::~Gun()
{
	DeleteGO(M_Gun.P_GunSight);
}
void Gun::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && !M_CoolDownFlag)
	{
		NewGO<Bullet>(0,"bullet");
		NewGO<GunSound>(0, "gunsound");
		M_CoolDownFlag = true;
	}else {
		if (M_CoolDownFlag)
		{
			M_CoolDownTime++;
			if (M_CoolDownTime >= M_CoolDownTimeFixed)
			{
				M_CoolDownFlag = false;
				M_CoolDownTime = 0;
			}
		}
	}
}