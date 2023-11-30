#pragma once
class Game;
class GameCamera;
class Gun;
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void PlayerMove();
	void PlayerDash();
	void PlayerFall();

	void InitValue();

	const Vector3& GetPosition()
	{return M_PlayerPosition;}
private:
	ModelRender M_PlayerModel;

	Vector3 M_PlayerPosition = { 0.0f,500.0f,0.0f };
	Vector3 M_PlayerSpeed    = { 0.0f,0.0f,0.0f };
	Vector3 M_PlayerForward  = { 0.0f,0.0f,0.0f };
	Vector3 M_PlayerRight    = { 0.0f,0.0f,0.0f };

	CharacterController M_PlayerController;

	bool M_FirstDashFlag = false;
	bool M_SecondDashFlag = false;
	bool M_DashFlag = false;

	int M_FirstTime = 0;
	int M_SecondTime = 5;

	Game* P_Game             = nullptr;
	GameCamera* P_GameCamera = nullptr;
	Gun* P_Gun               = nullptr;
	
	FontRender M_FX;
	wchar_t M_X[256];
};

