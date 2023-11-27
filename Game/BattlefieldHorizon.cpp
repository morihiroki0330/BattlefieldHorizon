#include "stdafx.h"
#include "BattlefieldHorizon.h"

#include "GameTitle.h"
#include "GameResult.h"
#include "Ui.h"

#include "Enemy.h"
#include "EnemyStatus.h"

#include "Player.h"
#include "PlayerStatus.h"

#include "TileMap.h"
#include "GameCamera.h"
#include "Sky.h"
#include "Fade.h"

BattlefieldHorizon::BattlefieldHorizon()
{
	Create(M_Number);
}
BattlefieldHorizon::~BattlefieldHorizon()
{

}
bool BattlefieldHorizon::Start()
{
	return true;
}
void BattlefieldHorizon::Update()
{
	S_Horizon.P_Fade = FindGO<Fade>("fade");
}
void BattlefieldHorizon::Create(int Number)
{
	switch (Number)
	{
	case 0:
		S_Horizon.P_GameTitle = NewGO<GameTitle>(0, "gametitle"); 
		break;
	case 1:
		DeleteGO(S_Horizon.P_GameTitle);
		S_Horizon.P_Fade->StartFadeIn();
		S_Horizon.P_Player = NewGO<Player>(0, "player");
		S_Horizon.P_TileMap = NewGO<TileMap>(0, "tilemap");
		S_Horizon.P_Sky = NewGO<Sky>(0, "sky");
		S_Horizon.P_GameCamera = NewGO<GameCamera>(0, "gamecamera");
		break;
	}
}