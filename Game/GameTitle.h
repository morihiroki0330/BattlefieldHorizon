#pragma once
class BattlefieldHorizon;

class DimensionalCollision;
class Fade;
class Mouse;

struct GameTitleButton
{
	SpriteRender M_BackGroundTexture;
	SpriteRender M_Cloud[10];
	SpriteRender M_TextTexture;

	Vector3 M_CloudPosition[10];
	Vector3 M_TextPosition = { 0.0f,300.0f,0.0f };

	int M_CloudCount;
	bool M_CloudFlag[10];

	SpriteRender M_StartButton;
	SpriteRender M_OptionButton;
	SpriteRender M_ExitButton;

	Vector3 M_StartButtonPosition = { 0.0f,100.0f,0.0f };
	Vector3 M_OptionButtonPosition = { 0.0f,-80.0f,0.0f };
	Vector3 M_ExitButtonPosition = { 0.0f,-260.0f,0.0f };

	bool M_StartFlag = false;
	bool M_OptionFlag = false;
	bool M_ExitFlag = false;
};
class GameTitle : public IGameObject
{
public:
	GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Button();
	void ButtonAfter();
	void Cloud();
private:
	
	GameTitleButton S_GameTitle;

	BattlefieldHorizon* P_Horizon = nullptr;
	DimensionalCollision* P_Collision = nullptr;
	Fade* P_Fade                      = nullptr;
	Mouse* P_Mouse                    = nullptr;
};

