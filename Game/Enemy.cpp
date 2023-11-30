#include "stdafx.h"
#include "Enemy.h"

#include "Player.h"
#include "Bullet.h"
#include "EnemySpawner.h"
bool Enemy::Start()
{
	M_EnemyModel.Init("Assets/modelData/Enemy/Enemy.tkm");
	M_EnemyController.Init(50.0f, 50.0f, M_EnemyPosition);
	P_Player = FindGO<Player>("player");
	P_EnemySpawner = FindGO<EnemySpawner>("enemyspawner");
	return true;
}
void Enemy::Update()
{
	P_Bullet = FindGO<Bullet>("bullet");
	if (P_Bullet != nullptr)
	{EnemyHit();}
	if (M_EnemyController.IsOnGround())
	{EnemyMove();}
	EnemyFall();
	EnemyDead();

	EnemyCoolTime();

	M_EnemyPosition = M_EnemyController.Execute(M_EnemySpeed, 1.0f / 60.0f);
	M_EnemyModel.SetPosition(M_EnemyPosition);
	M_EnemyModel.Update();
}
void Enemy::Render(RenderContext& rc)
{
	M_EnemyModel.Draw(rc);
}

void Enemy::EnemyMove()
{
	M_EnemySpeed.x = (P_Player->GetPosition().x - M_EnemyPosition.x);

	M_EnemySpeed.z = (P_Player->GetPosition().z - M_EnemyPosition.z);

}
void Enemy::EnemyFall()
{
	M_EnemySpeed.y -= 10.0f;
	if (M_EnemyPosition.y < -100.0f)
	{M_EnemyPosition.y = 500.0f;}
}
void Enemy::EnemyDead()
{
	if (M_EnemyHp <= 0)
	{
		P_EnemySpawner->EnemyDead();
		DeleteGO(this);
	}
}
void Enemy::EnemyHit()
{
	PhysicsWorld::GetInstance()->ContactTest(M_EnemyController, [&](const btCollisionObject& contactObject)
	{
		if (P_Bullet->BulletIsSelf(contactObject))
		{
			EnemyDamage();
			P_Bullet->BulletDead();
		}
	});
}
void Enemy::EnemyDamage()
{
	if (!M_CoolFlag)
	{
		M_EnemyHp -= 1;
		M_CoolFlag = true;
	}
}
void Enemy::EnemyCoolTime()
{
	if (M_CoolFlag)
	{
		M_CoolTime++;
		if (M_CoolTime > 25)
		{
			M_CoolTime = 0;
			M_CoolFlag = false;
		}
	}
}

void Enemy::InitValue()
{
	M_EnemySpeed.x = 0.0f;
	M_EnemySpeed.z = 0.0f;
}