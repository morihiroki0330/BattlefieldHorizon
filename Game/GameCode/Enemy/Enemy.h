#pragma once
#include "DimensionalStorage/StructStorage.h"
class Enemy : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void SetPosition(Vector3 Pos)
	{S_Enemy.M_EnemyPosition = Pos;}

	void EnemyMove();
	void EnemyFall();
	void EnemyDead();

	void EnemyHit();
	void EnemyDamage();
	void EnemyCoolTime();

	void InitValue();
private:
	DataEnemy S_Enemy;

	ClassPlayer S_Player;
	ClassGun S_Bullet;
	ClassEnemy S_EnemySpawner;
	/*Player* P_Player = nullptr;
	Bullet* P_Bullet = nullptr;
	EnemySpawner* P_EnemySpawner = nullptr;*/
};

