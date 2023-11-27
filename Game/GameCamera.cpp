#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"
bool GameCamera::Start()
{
	g_camera3D->SetFar(1500000.0f);
	P_Player = FindGO<Player>("player");
	M_CameraPosition.y = P_Player->GetPosition().y + M_CameraPosition.y;
	return true;
}

void GameCamera::Update()
{
	M_CameraPosition.x = P_Player->GetPosition().x;
	M_CameraPosition.y = P_Player->GetPosition().y+100.0f;
	M_CameraPosition.z = P_Player->GetPosition().z;

	g_camera3D->SetPosition(M_CameraPosition);
	g_camera3D->SetTarget(M_CameraTarget);
}

void GameCamera::CameraMove(Vector2 Position)
{
	M_MovePosition.x = (int)(Position.x);
	M_MovePosition.y = (int)(Position.y);

	RightMove(M_MovePosition);
	LeftMove(M_MovePosition);

	CameraJust();
	AngleJust();
}
void GameCamera::RightMove(Vector2 Position)
{
	if (Position.x > 0.0f)
	{
		if ((M_CameraTarget.x > 0.0f || M_CameraTarget.x == 0.0f) && (M_CameraTarget.z > 0.0f))
		{
			M_CameraTarget.x += (abs(Position.x) * M_MagniFication);
			M_CameraTarget.z -= (abs(Position.x) * M_MagniFication);
		}else {
			if ((M_CameraTarget.x > 0.0f) && (M_CameraTarget.z < 0.0f || M_CameraTarget.z == 0.0f))
			{
				M_CameraTarget.x -= (abs(Position.x) * M_MagniFication);
				M_CameraTarget.z -= (abs(Position.x) * M_MagniFication);
			}else {
				if ((M_CameraTarget.x < 0.0f || M_CameraTarget.x == 0.0f) && (M_CameraTarget.z < 0.0f))
				{
					M_CameraTarget.x -= (abs(Position.x) * M_MagniFication);
					M_CameraTarget.z += (abs(Position.x) * M_MagniFication);
				}else {
					if ((M_CameraTarget.x < 0.0f) && (M_CameraTarget.z > 0.0f || M_CameraTarget.z == 0.0f))
					{
						M_CameraTarget.x += (abs(Position.x) * M_MagniFication);
						M_CameraTarget.z += (abs(Position.x) * M_MagniFication);
					}
				}
			}
		}
		M_Angle += Position.x;
	}
}
void GameCamera::LeftMove(Vector2 Position)
{

	if (Position.x < 0.0f)
	{
		if ((M_CameraTarget.x < 0.0f || M_CameraTarget.x == 0.0f) && (M_CameraTarget.z > 0.0f))
		{
			M_CameraTarget.x -= (abs(Position.x) * M_MagniFication);
			M_CameraTarget.z -= (abs(Position.x) * M_MagniFication);
		}else {
			if ((M_CameraTarget.x < 0.0f) && (M_CameraTarget.z < 0.0f || M_CameraTarget.z == 0.0f))
			{
				M_CameraTarget.x += (abs(Position.x) * M_MagniFication);
				M_CameraTarget.z -= (abs(Position.x) * M_MagniFication);
			}else {
				if ((M_CameraTarget.x > 0.0f || M_CameraTarget.x == 0.0f) && (M_CameraTarget.z < 0.0f))
				{
					M_CameraTarget.x += (abs(Position.x) * M_MagniFication);
					M_CameraTarget.z += (abs(Position.x) * M_MagniFication);
				}else {
					if ((M_CameraTarget.x > 0.0f) && (M_CameraTarget.z > 0.0f || M_CameraTarget.z == 0.0f))
					{
						M_CameraTarget.x -= (abs(Position.x) * M_MagniFication);
						M_CameraTarget.z += (abs(Position.x) * M_MagniFication);
					}
				}
			}
		}
		M_Angle += Position.x;
	}
}

void GameCamera::CameraJust()
{
	if ((abs)(M_CameraTarget.x) + (abs)(M_CameraTarget.z) != M_CircleFication)
	{
		if (M_Angle > 0)
		{
			if (M_Angle <= 480)
			{
				M_CameraTarget.x = M_MagniFication * M_Angle;
				M_CameraTarget.z = M_CircleFication - M_CameraTarget.x;
			}else {
				if (M_Angle <= 960)
				{
					M_CameraTarget.z = (480 - M_Angle) * M_MagniFication;
					M_CameraTarget.x = M_CircleFication + M_CameraTarget.z;
				}else {
					if (M_Angle <= 1440)
					{
						M_CameraTarget.x = (960 - M_Angle) * M_MagniFication;
						M_CameraTarget.z = -(M_CircleFication + M_CameraTarget.x);
					}else {
						if (M_Angle <= 1920)
						{
							M_CameraTarget.z = (1440 - M_Angle) * -M_MagniFication;
							M_CameraTarget.x = -(M_CircleFication - M_CameraTarget.z);
						}
					}
				}
			}
		}else {
			if (M_Angle < 0)
			{
				if (M_Angle >= -480)
				{
					M_CameraTarget.x = M_MagniFication * M_Angle;
					M_CameraTarget.z = M_CircleFication + M_CameraTarget.x;
				}else {
					if (M_Angle >= -960)
					{
						M_CameraTarget.z = (480 + M_Angle) * M_MagniFication;
						M_CameraTarget.x = -(M_CircleFication + M_CameraTarget.z);
					}else {
						if (M_Angle >= -1440)
						{
							M_CameraTarget.x = (960 + M_Angle) * -M_MagniFication;
							M_CameraTarget.z = -(M_CircleFication - M_CameraTarget.x);
						}else {
							if (M_Angle >= -1920)
							{
								M_CameraTarget.z = (1440 + M_Angle) * -M_MagniFication;
								M_CameraTarget.x = (M_CircleFication - M_CameraTarget.z);
							}
						}
					}
				}
			}else {
				if (M_Angle == 0)
				{
					M_CameraTarget.x = 0.0f;
					M_CameraTarget.z = M_CircleFication;
				}
			}
		}
	}

	if (M_MovePosition.y < 0.0f)
	{
		M_CameraTarget.y += (abs(M_MovePosition.y) * M_MagniFication);
	}else {
		if (M_MovePosition.y > 0.0f)
		{
			M_CameraTarget.y -= (abs(M_MovePosition.y) * M_MagniFication);
		}
	}
}
void GameCamera::AngleJust()
{
	if (M_Angle > 1920)
	{
		M_Angle = 0;
	}else {
		if (M_Angle < -1920)
		{
			M_Angle = 0;
		}
	}
}