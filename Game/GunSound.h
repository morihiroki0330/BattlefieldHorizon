#pragma once
class Sound;
class Gun;
class GunSound : public IGameObject
{
public:
	GunSound();
	void Update()
	{
		if (!P_GunSe->IsPlaying())
		{DeleteGO(this);}
	}
private:
	Gun* P_Gun           = nullptr;
	SoundSource* P_GunSe = nullptr;
	Sound* P_Sound       = nullptr;
};

