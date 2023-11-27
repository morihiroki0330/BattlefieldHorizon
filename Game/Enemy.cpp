#include "stdafx.h"
#include "Enemy.h"

#include "Player.h"
#include "Gun.h"
bool Enemy::Start()
{
	P_Gun = NewGO<Gun>(0, "gun");
	M_EnemyModel.Init("Assets/modelData/Enemy/Enemy.tkm");
	M_EnemyController.Init(75.0f, 50.0f, M_EnemyPosition);
	return true;
}
void Enemy::Update()
{
	P_Player = FindGO<Player>("player");

	EnemyMove();
	EnemyFall();
	EnemyDead();

	M_EnemyModel.SetPosition(M_EnemyPosition);
	M_EnemyModel.Update();
}
void Enemy::Render(RenderContext& rc)
{
	M_EnemyModel.Draw(rc);
}

void Enemy::EnemyMove()
{

}
void Enemy::EnemyFall()
{

}
void Enemy::EnemyDead()
{
	if (M_EnemyHp < 0)
	{DeleteGO(this);}
}