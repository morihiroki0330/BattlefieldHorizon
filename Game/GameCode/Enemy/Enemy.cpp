#include "stdafx.h"
#include "Enemy.h"

#include "GameCode/GameCode.h"
bool Enemy::Start()
{
	S_Enemy.M_EnemyModel.Init("Assets/modelData/Enemy/Enemy.tkm");
	S_Enemy.M_EnemyController.Init(50.0f, 50.0f, S_Enemy.M_EnemyPosition);
	S_Player.P_Player = FindGO<Player>("player");
	S_EnemySpawner.P_EnemySpawner = FindGO<EnemySpawner>("enemyspawner");
	return true;
}
void Enemy::Update()
{
	S_Bullet.P_Bullet = FindGO<Bullet>("bullet");
	if (S_Bullet.P_Bullet != nullptr)
	{EnemyHit();}
	if (S_Enemy.M_EnemyController.IsOnGround())
	{EnemyMove();}
	EnemyFall();
	EnemyDead();

	EnemyCoolTime();

	S_Enemy.M_EnemyPosition = S_Enemy.M_EnemyController.Execute(S_Enemy.M_EnemySpeed, 1.0f / 60.0f);
	S_Enemy.M_EnemyModel.SetPosition(S_Enemy.M_EnemyPosition);
	S_Enemy.M_EnemyModel.Update();
}
void Enemy::Render(RenderContext& rc)
{
	S_Enemy.M_EnemyModel.Draw(rc);
}

void Enemy::EnemyMove()
{
	S_Enemy.M_EnemySpeed.x = (S_Player.P_Player->GetPosition().x - S_Enemy.M_EnemyPosition.x);

	S_Enemy.M_EnemySpeed.z = (S_Player.P_Player->GetPosition().z - S_Enemy.M_EnemyPosition.z);
}
void Enemy::EnemyFall()
{
	S_Enemy.M_EnemySpeed.y -= 10.0f;
	if (S_Enemy.M_EnemyPosition.y < -100.0f)
	{S_Enemy.M_EnemyPosition.y = 500.0f;}
}
void Enemy::EnemyDead()
{
	if (S_Enemy.M_EnemyHp <= 0)
	{
		S_EnemySpawner.P_EnemySpawner->EnemyDead();
		DeleteGO(this);
	}
}
void Enemy::EnemyHit()
{
	PhysicsWorld::GetInstance()->ContactTest(S_Enemy.M_EnemyController, [&](const btCollisionObject& contactObject)
	{
		if (S_Bullet.P_Bullet->BulletIsSelf(contactObject))
		{
			EnemyDamage();
			S_Bullet.P_Bullet->BulletDead();
		}
	});
}
void Enemy::EnemyDamage()
{
	if (!S_Enemy.M_CoolFlag)
	{
		S_Enemy.M_EnemyHp -= 1;
		S_Enemy.M_CoolFlag = true;
	}
}
void Enemy::EnemyCoolTime()
{
	if (S_Enemy.M_CoolFlag)
	{
		S_Enemy.M_CoolTime++;
		if (S_Enemy.M_CoolTime > 25)
		{
			S_Enemy.M_CoolTime = 0;
			S_Enemy.M_CoolFlag = false;
		}
	}
}

void Enemy::InitValue()
{
	S_Enemy.M_EnemySpeed.x = 0.0f;
	S_Enemy.M_EnemySpeed.z = 0.0f;
}