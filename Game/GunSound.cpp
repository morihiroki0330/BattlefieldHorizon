#include "stdafx.h"
#include "GunSound.h"

#include "Sound.h"
#include "Gun.h"
GunSound::GunSound()
{
	P_GunSe = NewGO<SoundSource>(0);
	P_Gun = FindGO<Gun>("gun");
	P_Sound = FindGO<Sound>("sound");
	P_GunSe->Init(SE_GUNSHOT);
	P_GunSe->SetVolume(P_Sound->GetSeVolume());
	P_GunSe->Play(false);
}