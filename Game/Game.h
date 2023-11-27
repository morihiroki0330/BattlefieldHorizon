#pragma once
class BattlefieldHorizon;

class DimensionalCollision;
class Sound;
class GameCamera;
class Mouse;
class Fade;

struct GameClass
{
	BattlefieldHorizon* P_Horizon = nullptr;
};
struct ToolClass
{
	DimensionalCollision* P_Collision = nullptr;
	Sound* P_Sound                    = nullptr;
	GameCamera* P_GameCamera          = nullptr;
	Mouse* P_Mouse                    = nullptr;
	Fade* P_Fade                      = nullptr;
};
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void InitValue();

	Vector2 GetLStick()
	{return M_LStick;}
	Vector2 GetRStick()
	{return M_RStick;}

private:
	GameClass S_Game;
	ToolClass S_Tool;

	Vector2 M_LStick = { 0.0f,0.0f };
	Vector2 M_RStick = { 0.0f,0.0f };
};

