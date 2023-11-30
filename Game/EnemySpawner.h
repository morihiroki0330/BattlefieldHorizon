#pragma once
class Enemy;
class Player;
class Bullet;
class BattlefieldHorizon;
class EnemySpawner : public IGameObject
{
public:
	EnemySpawner();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void EnemyCreate();
	void EnemyDead()
	{M_EnemyCount--;}
	void EnemyGenerate()
	{M_EnemyCount++;}
private:
	ModelRender M_EnemySpawnerModel;
	Vector3 M_EnemySpawnerPosition = { 0.0f,200.0f,0.0f };
	Vector3 M_EnemySetPosition = { 0.0f,500.0f,0.0f };
	
	Enemy* P_Enemy = nullptr;
	Player* P_Player = nullptr;
	BattlefieldHorizon* P_Horizon = nullptr;

	int M_EnemyCount = 0;
	int M_EnemyCountMax = 1;
	int M_Level = 1;
	bool Flag = true;

	float AngleX = rand() % 381 - 190;
	float AngleZ = rand() % 381 - 190;
};

