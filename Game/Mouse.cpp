#include "stdafx.h"
#include "Mouse.h"
#include "BattlefieldHorizon.h"
#include "GameCamera.h"
#include "DimensionalCollision.h"
#include "NumberStorage.h"
bool Mouse::Start()
{
	ShowCursor(false);
	P_Horizon = FindGO<BattlefieldHorizon>("horizon");
	P_Collision = FindGO<DimensionalCollision>("collision");
	
	M_MouseCursorTexture.Init("Assets/Sprite/Gun/Sight/Sight.DDS", 150.0f, 150.0f, true);
	P_Collision->DecisionDataSet(100, 100, M_MouseCousorPosition.x, M_MouseCousorPosition.y, COLLISION_CURSOR, TAG_NON);
    return true;
}
void Mouse::Update()
{
	P_GameCamera = FindGO<GameCamera>("gamecamera");
	
    GetCursorPos(&M_CursorPosition);
    ScreenToClient(M_HWnd, &M_CursorPosition);
    MouseSet();
	MouseFlagJudge();
	if (P_GameCamera != nullptr)
	{
		MouseMove();
	}else {
	if (P_GameCamera == nullptr)
	{
		MouseCurSorSetPosition(M_MouseCousorPosition);
		M_MouseCursorTexture.SetPosition(M_MouseCousorPosition);
		P_Collision->DecisionSetPosition(M_MouseCousorPosition.x, M_MouseCousorPosition.y, COLLISION_CURSOR);
		M_MouseCursorTexture.Update();
	}
	}
}
void Mouse::Render(RenderContext& rc)
{
	if (P_GameCamera == nullptr)
	{M_MouseCursorTexture.Draw(rc);}
}

void Mouse::MouseSet()
{
    M_Converted.x = (M_CursorPosition.x * M_Window.x) / M_Client.x;
    M_Converted.y = (M_CursorPosition.y * M_Window.y) / M_Client.y;

    M_Mouse.x = M_Converted.x;
    M_Mouse.y = M_Converted.y;
}
void Mouse::MouseMove()
{
    M_Delta.x = M_Mouse.x - M_PrevMouse.x;
    M_Delta.y = M_Mouse.y - M_PrevMouse.y;

    M_PrevMouse.x = M_Mouse.x;
    M_PrevMouse.y = M_Mouse.y;

    if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
    {
        P_GameCamera->CameraMove(M_Delta);
    }else { 
        MouseReset();
    }
}
void Mouse::MouseReset()
{
	SetCursorPos(M_Client.x / 2, M_Client.y / 2);
}

void Mouse::MouseCurSorSetPosition(Vector3& Position)
{
	Position.x = (M_Converted.x - (M_Window.x / 2));
	Position.y = (M_Converted.y - (M_Window.y / 2)) * -1;
}

void Mouse::MouseFlagJudge()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		S_Flag.M_LeftButtonFlag = true;
	}else{
		S_Flag.M_LeftButtonFlag = false;
	}

	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		S_Flag.M_RightButtonFlag = true;
	}else{
		S_Flag.M_RightButtonFlag = false;
	}

}
void Mouse::SetMouseFlag(int Number, bool Flag)
{
	switch (Number)
	{
	case LEFTBUTTON:
		S_Flag.M_LeftButtonFlag = Flag;
		break;
	case RIGHTBUTTON:
		S_Flag.M_RightButtonFlag = Flag;
		break;
	}
}
bool Mouse::GetMouseFlag(int Number)
{
	switch (Number)
	{
	case LEFTBUTTON:
		return S_Flag.M_LeftButtonFlag;
		break;
	case RIGHTBUTTON:
		return S_Flag.M_RightButtonFlag;
		break;
	}
}