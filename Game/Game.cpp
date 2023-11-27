#include "stdafx.h"
#include "Game.h"
#include "BattlefieldHorizon.h"

#include "Player.h"
#include "TileMap.h"

#include "DimensionalCollision.h"
#include "Sound.h"
#include "GameCamera.h"
#include "Mouse.h"
#include "Fade.h"
Game::Game()
{
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	S_Game.P_Horizon = NewGO<BattlefieldHorizon>(0, "horizon");

	S_Tool.P_Collision  = NewGO<DimensionalCollision>(0, "collision");
	S_Tool.P_Sound      = NewGO<Sound>(0, "sound");
	
	S_Tool.P_Mouse      = NewGO<Mouse>(0, "mouse");
	S_Tool.P_Fade       = NewGO<Fade>(1, "fade");
}

Game::~Game()
{
	DeleteGO(S_Game.P_Horizon);
	
	DeleteGO(S_Tool.P_Collision);
	DeleteGO(S_Tool.P_Sound);
	DeleteGO(S_Tool.P_Mouse);
	DeleteGO(S_Tool.P_Fade);
}

void Game::Update()
{
	S_Tool.P_GameCamera = FindGO<GameCamera>("gamecamera");
	InitValue();
	if (S_Tool.P_GameCamera != nullptr)
	{S_Tool.P_GameCamera->CameraMove(M_RStick);}
}
void Game::InitValue()
{
	M_LStick.x = g_pad[0]->GetLStickXF();
	M_LStick.y = g_pad[0]->GetLStickYF();

	M_RStick.x = g_pad[0]->GetRStickXF();
	M_RStick.y = g_pad[0]->GetRStickYF();

	M_RStick.x *= 10.0f;
	M_RStick.y *= -10.0f;
}