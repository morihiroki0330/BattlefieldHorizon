#include "stdafx.h"
#include "Player.h"

#include "Game.h"
#include "GameCamera.h"
#include "Gun.h"
Player::Player()
{	
	P_Gun = NewGO<Gun>(0,"gun");

	M_PlayerModel.Init("Assets/modelData/Character/Character.tkm");

	M_PlayerController.Init(75.0f, 50.0f, M_PlayerPosition);
}

Player::~Player()
{
	DeleteGO(P_Gun);
}

bool Player::Start()
{
	P_Game = FindGO<Game>("game");
	P_GameCamera = FindGO<GameCamera>("gamecamera");
	return true;
}

void Player::Update()
{
	InitValue();
	
	PlayerDash();
	PlayerMove();
	PlayerFall();

    M_PlayerPosition = M_PlayerController.Execute(M_PlayerSpeed, 1.0f / 60.0f);
    M_PlayerModel.SetPosition(M_PlayerPosition);
	M_PlayerModel.Update();

	swprintf_s(M_X, 256, L"%f", M_PlayerPosition.y);
	M_FX.SetText(M_X);
	M_FX.SetPosition({300.0f,0.0f,0.0f});
	M_FX.SetScale(1.0f);
}

void Player::PlayerMove()
{
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || M_DashFlag)
	{
		M_PlayerRight *= P_Game->GetLStick().x * 900.0f;
		M_PlayerForward *= P_Game->GetLStick().y * 900.0f;
	}else {
		M_PlayerRight *= P_Game->GetLStick().x * 300.0f;
		M_PlayerForward *= P_Game->GetLStick().y * 300.0f;
	}
	M_PlayerSpeed.x += M_PlayerRight.x + M_PlayerForward.x;
	M_PlayerSpeed.z += M_PlayerRight.z + M_PlayerForward.z;
}
void Player::PlayerDash()
{
	if (P_Game->GetLStick().x != 0.0f || P_Game->GetLStick().y != 0.0f)
	{
		if (!M_FirstDashFlag)
		{
			M_FirstDashFlag = true;
		}else {
			if (M_FirstDashFlag && M_SecondDashFlag && !M_DashFlag )
			{
				M_DashFlag = true;
			}
		}
	}else {
		if (M_FirstDashFlag)
		{
			M_FirstTime++;
			M_SecondDashFlag = true;
			if (M_FirstTime > M_SecondTime)
			{
				M_FirstDashFlag = false;
				M_SecondDashFlag = false;
				M_FirstTime = 0;
			}
		}

		if (M_DashFlag)
		{
			M_DashFlag = false;
			M_FirstDashFlag = false;
			M_SecondDashFlag = false;
			M_FirstTime = 0;
		}
	}
}
void Player::PlayerFall()
{
	M_PlayerSpeed.y -= 10.0f;
	if (M_PlayerPosition.y > 1900.0f)
	{M_PlayerPosition.y = 500.0f;}
}

void Player::InitValue()
{
	M_PlayerSpeed.x = 0.0f;
	M_PlayerSpeed.z = 0.0f;
	
	M_PlayerForward = g_camera3D->GetForward();
	M_PlayerRight = g_camera3D->GetRight();
	
	M_PlayerForward.y = 0.0f;
	M_PlayerRight.y   = 0.0f;
}

void Player::Render(RenderContext& rc)
{
	M_PlayerModel.Draw(rc);
	M_FX.Draw(rc);
}
