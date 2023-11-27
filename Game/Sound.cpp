#include "stdafx.h"
#include "Sound.h"
#include "sound/SoundEngine.h"
Sound::Sound()
{
	g_soundEngine->ResistWaveFileBank(SE_GUNSHOT,"Assets/Sound/Se/GunSe.wav");
}