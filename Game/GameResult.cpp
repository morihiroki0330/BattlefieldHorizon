#include "stdafx.h"
#include "GameResult.h"

#include "BattlefieldHorizon.h"
#include "DimensionalCollision.h"
#include "Mouse.h"
#include "NumberStorage.h"
GameResult::GameResult()
{
	M_GameResultTexture.Init("Assets/Sprite/GameResult/BackGround.DDS", 1920.0f, 1080.0f, true);
	M_ResultButton.Init("Assets/Sprite/GameResult/ResultButton.DDS", 300.0f, 150.0f, true);
}
bool GameResult::Start()
{
	P_Horizon = FindGO<BattlefieldHorizon>("horizon");
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Mouse = FindGO<Mouse>("mouse");
	P_Collision->DecisionDataSet(M_ResultButton.GetWideAndHeight().x, M_ResultButton.GetWideAndHeight().y, 0.0f, 0.0f, COLLISION_RESULTBUTTON, TAG_NON);
	return true;
}
void GameResult::Update()
{
	if (P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_RESULTBUTTON) && P_Mouse->GetMouseFlag(LEFTBUTTON))
	{
		P_Horizon->Create(0);
	}
	M_GameResultTexture.Update();
	M_ResultButton.Update();
}
void GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
	M_ResultButton.Draw(rc);
}