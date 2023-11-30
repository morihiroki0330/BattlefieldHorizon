#pragma once
class Player;
class Bullet;
class EnemySpawner;
class Enemy : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void SetPosition(Vector3 Pos)
	{M_EnemyPosition = Pos;}

	void EnemyMove();
	void EnemyFall();
	void EnemyDead();

	void EnemyHit();
	void EnemyDamage();
	void EnemyCoolTime();

	void InitValue();
private:
	ModelRender M_EnemyModel;
	Vector3 M_EnemyPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_EnemySpeed = { 0.0f,0.0f,0.0f };
	CharacterController M_EnemyController;

	Player* P_Player = nullptr;
	Bullet* P_Bullet = nullptr;
	EnemySpawner* P_EnemySpawner = nullptr;

	int M_EnemyHp = 2;
	int M_CoolTime = 0;
	bool M_CoolFlag = false;
};

