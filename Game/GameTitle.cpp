#include "stdafx.h"
#include "GameTitle.h"

#include "BattlefieldHorizon.h"

#include "DimensionalCollision.h"
#include "Fade.h"
#include "Mouse.h"
#include "NumberStorage.h"
GameTitle::GameTitle()
{
	S_GameTitle.M_BackGroundTexture.Init("Assets/Sprite/GameTitle/BackGround.DDS", 1920.0f, 1080.0f, true);
	S_GameTitle.M_TextTexture.Init("Assets/Sprite/GameTitle/Text.DDS", 1520.0f, 150.0f, true);

	S_GameTitle.M_StartButton.Init("Assets/Sprite/GameTitle/StartButton.DDS", 300.0f, 150.0f, true);
	S_GameTitle.M_OptionButton.Init("Assets/Sprite/GameTitle/OptionButton.DDS", 300.0f, 150.0f, true);
	S_GameTitle.M_ExitButton.Init("Assets/Sprite/GameTitle/ExitButton.DDS", 300.0f, 150.0f, true);
}
bool GameTitle::Start()
{
	P_Horizon   = FindGO<BattlefieldHorizon>("horizon");
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Fade      = FindGO<Fade>("fade");
	P_Mouse     = FindGO<Mouse>("mouse");

	P_Collision->DecisionDataSet(S_GameTitle.M_StartButton.GetWideAndHeight().x  , S_GameTitle.M_StartButton.GetWideAndHeight().y  , S_GameTitle.M_StartButtonPosition.x  , S_GameTitle.M_StartButtonPosition.y  , COLLISION_STARTBUTTON , TAG_NON);
	P_Collision->DecisionDataSet(S_GameTitle.M_OptionButton.GetWideAndHeight().x , S_GameTitle.M_OptionButton.GetWideAndHeight().y , S_GameTitle.M_OptionButtonPosition.x , S_GameTitle.M_OptionButtonPosition.y , COLLISION_OPTIONBUTTON , TAG_NON);
	P_Collision->DecisionDataSet(S_GameTitle.M_ExitButton.GetWideAndHeight().x   , S_GameTitle.M_ExitButton.GetWideAndHeight().y   , S_GameTitle.M_ExitButtonPosition.x   , S_GameTitle.M_ExitButtonPosition.y   , COLLISION_EXITBUTTON , TAG_NON);
	return true;
}
void GameTitle::Update()
{
	Cloud();
	Button();
	ButtonAfter();

	P_Collision->DecisionSetPosition(S_GameTitle.M_StartButtonPosition.x  , S_GameTitle.M_StartButtonPosition.y  , COLLISION_STARTBUTTON);
	P_Collision->DecisionSetPosition(S_GameTitle.M_OptionButtonPosition.x , S_GameTitle.M_OptionButtonPosition.y , COLLISION_OPTIONBUTTON);
	P_Collision->DecisionSetPosition(S_GameTitle.M_ExitButtonPosition.x   , S_GameTitle.M_ExitButtonPosition.y   , COLLISION_EXITBUTTON);

	S_GameTitle.M_TextTexture.SetPosition(S_GameTitle.M_TextPosition);
	S_GameTitle.M_StartButton.SetPosition(S_GameTitle.M_StartButtonPosition);
	S_GameTitle.M_OptionButton.SetPosition(S_GameTitle.M_OptionButtonPosition);
	S_GameTitle.M_ExitButton.SetPosition(S_GameTitle.M_ExitButtonPosition);

	S_GameTitle.M_BackGroundTexture.Update();
	S_GameTitle.M_TextTexture.Update();
	S_GameTitle.M_StartButton.Update();
	S_GameTitle.M_OptionButton.Update();
	S_GameTitle.M_ExitButton.Update();
}
void GameTitle::Render(RenderContext& rc)
{
	S_GameTitle.M_BackGroundTexture.Draw(rc);
	S_GameTitle.M_TextTexture.Draw(rc);
	S_GameTitle.M_StartButton.Draw(rc);
	S_GameTitle.M_OptionButton.Draw(rc);
	S_GameTitle.M_ExitButton.Draw(rc);
}

void GameTitle::Button()
{
	if (P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_STARTBUTTON) && P_Mouse->GetMouseFlag(LEFTBUTTON))
	{
		if (!S_GameTitle.M_StartFlag && !S_GameTitle.M_OptionFlag && !S_GameTitle.M_ExitFlag)
		{
			P_Fade->StartFadeOut();
			S_GameTitle.M_StartFlag = true;
		}
	}else {
		if (P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_OPTIONBUTTON) && P_Mouse->GetMouseFlag(LEFTBUTTON))
		{
			if (!S_GameTitle.M_StartFlag && !S_GameTitle.M_OptionFlag && !S_GameTitle.M_ExitFlag)
			{
				S_GameTitle.M_OptionFlag = true;
			}
		}else {
			if (P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_EXITBUTTON) && P_Mouse->GetMouseFlag(LEFTBUTTON))
			{
				if (!S_GameTitle.M_StartFlag && !S_GameTitle.M_OptionFlag && !S_GameTitle.M_ExitFlag)
				{
					P_Fade->StartFadeOut();
					S_GameTitle.M_ExitFlag = true;
				}
			}
		}
	}
}
void GameTitle::ButtonAfter()
{
	if (!P_Fade->IsFade())
	{
		if (S_GameTitle.M_StartFlag)
		{
			P_Horizon->Create(1);
		}else {
			if (S_GameTitle.M_OptionFlag)
			{

			}else {
				if (S_GameTitle.M_ExitFlag)
				{
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}
void GameTitle::Cloud()
{

}