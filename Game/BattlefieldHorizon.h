#pragma once
//ステージは19000.0f*19000.0f
class GameTitle;
class GameResult;
class Ui;

class Enemy;
class EnemyStatus;
class EnemySpawner;

class Player;
class PlayerStatus;

class TileMap;
class GameCamera;
class Sky;
class Fade;
class DimensionalCollision;

struct BattlefieldHorizonClass
{
	GameTitle* P_GameTitle   = nullptr;
	GameResult* P_GameResult = nullptr;
	Ui* P_Ui                 = nullptr;

	Enemy* P_Enemy             = nullptr;
	EnemyStatus* P_EnemyStatus = nullptr;
	EnemySpawner* P_EnemySpawner = nullptr;

	Player* P_Player             = nullptr;
	PlayerStatus* P_PlayerStatus = nullptr;

	TileMap* P_TileMap           = nullptr;
	GameCamera* P_GameCamera = nullptr;
	Sky* P_Sky = nullptr;
	Fade* P_Fade = nullptr;
	DimensionalCollision* P_Collision = nullptr;
};
class BattlefieldHorizon : public IGameObject
{
public:
	BattlefieldHorizon();
	~BattlefieldHorizon();
	bool Start();
	void Update();
	void Create(int Number);
	
	void Reset();
	void ClearFlag()
	{M_ClearFlag = true;}
private:
	BattlefieldHorizonClass S_Horizon;

	bool Clear = false;
	bool M_ClearFlag = false;
};

