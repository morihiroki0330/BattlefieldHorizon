#pragma once
class GameTitle;
class GameResult;
class Ui;

class Enemy;
class EnemyStatus;

class Player;
class PlayerStatus;

class TileMap;
class GameCamera;
class Sky;
class Fade;

struct BattlefieldHorizonClass
{
	GameTitle* P_GameTitle   = nullptr;
	GameResult* P_GameResult = nullptr;
	Ui* P_Ui                 = nullptr;

	Enemy* P_Enemy             = nullptr;
	EnemyStatus* P_EnemyStatus = nullptr;

	Player* P_Player             = nullptr;
	PlayerStatus* P_PlayerStatus = nullptr;

	TileMap* P_TileMap           = nullptr;
	GameCamera* P_GameCamera = nullptr;
	Sky* P_Sky = nullptr;
	Fade* P_Fade = nullptr;
};
class BattlefieldHorizon : public IGameObject
{
public:
	BattlefieldHorizon();
	~BattlefieldHorizon();
	bool Start();
	void Update();
	void Create(int Number);
private:
	BattlefieldHorizonClass S_Horizon;
	int M_Number = 0;
};

