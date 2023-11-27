#pragma once
class Player;
class Gun;
class Enemy : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void EnemyMove();
	void EnemyFall();
	void EnemyDead();
private:
	ModelRender M_EnemyModel;
	Vector3 M_EnemyPosition = { 0.0f,5000.0f,0.0f };
	CharacterController M_EnemyController;

	Player* P_Player = nullptr;
	Gun* P_Gun = nullptr;

	int M_EnemyHp = 5;
	int M_CoolTime = 60;
};

