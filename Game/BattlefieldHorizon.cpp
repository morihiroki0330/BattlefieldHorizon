#include "stdafx.h"
#include "BattlefieldHorizon.h"

#include "GameTitle.h"
#include "GameResult.h"
#include "Ui.h"

#include "Enemy.h"
#include "EnemyStatus.h"
#include "EnemySpawner.h"

#include "Player.h"
#include "PlayerStatus.h"

#include "TileMap.h"
#include "GameCamera.h"
#include "Sky.h"
#include "SkyCube.h"
#include "Fade.h"
#include "DimensionalCollision.h"
#include "NumberStorage.h"

BattlefieldHorizon::BattlefieldHorizon()
{
	Create(0);
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
	S_Horizon.P_Collision = FindGO<DimensionalCollision>("collision");

	if (M_ClearFlag)
	{
		S_Horizon.P_Fade->StartFadeOut();
		Clear = true;
		M_ClearFlag = false;
	}

	if (!S_Horizon.P_Fade->IsFade())
	{
		if (Clear)
		{
			Create(2);
			Clear = false;
		}
	}
}
void BattlefieldHorizon::Reset()
{
	bool Clear = false;
	bool M_ClearFlag = false;
}
void BattlefieldHorizon::Create(int Number)
{
	switch (Number)
	{
	case 0:
		if (S_Horizon.P_GameResult != nullptr)
		{
			DeleteGO(S_Horizon.P_GameResult);
			S_Horizon.P_Collision->DecisionDataDelete(COLLISION_STARTBUTTON);
			S_Horizon.P_Collision->DecisionDataDelete(COLLISION_OPTIONBUTTON);
			S_Horizon.P_Collision->DecisionDataDelete(COLLISION_EXITBUTTON);
			S_Horizon.P_Collision->DecisionDataDelete(COLLISION_RESULTBUTTON);
			Reset();
		}
		S_Horizon.P_GameTitle = NewGO<GameTitle>(0, "gametitle"); 
		break;
	case 1:
		DeleteGO(S_Horizon.P_GameTitle);
		S_Horizon.P_Fade->StartFadeIn();
		S_Horizon.P_Player = NewGO<Player>(0, "player");
		S_Horizon.P_TileMap = NewGO<TileMap>(0, "tilemap");
		S_Horizon.P_Sky = NewGO<Sky>(0, "sky");
		S_Horizon.P_GameCamera = NewGO<GameCamera>(0, "gamecamera");
		S_Horizon.P_EnemySpawner = NewGO<EnemySpawner>(0, "enemyspawner");
		break;
	case 2:
		DeleteGO(S_Horizon.P_Player);
		DeleteGO(S_Horizon.P_TileMap);
		DeleteGO(S_Horizon.P_Sky);
		DeleteGO(S_Horizon.P_GameCamera);
		DeleteGO(S_Horizon.P_EnemySpawner);
		S_Horizon.P_Fade->StartFadeIn();
		S_Horizon.P_GameResult = NewGO<GameResult>(0, "gameresult");
	}
}