#include "stdafx.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "Player.h"
#include "BattlefieldHorizon.h"
#include <cstdlib>
EnemySpawner::EnemySpawner()
{
	M_EnemySpawnerModel.Init("Assets/modelData/Enemy/EnemySpawner.tkm");
}
bool EnemySpawner::Start()
{
	/*P_Enemy = NewGO<Enemy>(0, "enemy");
	P_Enemy->SetPosition({600.0f,500.0f,600.0f});
	EnemyGenerate();
	P_Enemy = NewGO<Enemy>(0, "enemy");
	P_Enemy->SetPosition({ -600.0f,500.0f,600.0f });
	EnemyGenerate();*/
	P_Player = FindGO<Player>("player");
	P_Horizon = FindGO<BattlefieldHorizon>("horizon");
	M_EnemySpawnerPosition.x = P_Player->GetPosition().x;
	M_EnemySpawnerPosition.z = P_Player->GetPosition().z + 500.0f;
	EnemyCreate();
	return true;
}
void EnemySpawner::Update()
{
	if (M_EnemyCount <= 0 && Flag)
	{
		P_Horizon->ClearFlag();
		Flag = false;
	}
	M_EnemySpawnerModel.SetPosition(M_EnemySpawnerPosition);
	M_EnemySpawnerModel.Update();
}
void EnemySpawner::Render(RenderContext& rc)
{
	M_EnemySpawnerModel.Draw(rc);
}

void EnemySpawner::EnemyCreate()
{
	for (int Level = 0; Level < M_Level; Level++)
	{
		for (int EnemyCount = 0; EnemyCount < M_EnemyCountMax; EnemyCount++)
		{
			do
			{
				AngleX = rand() % 381 - 190;
				M_EnemySetPosition.x = AngleX * 100.0f;
			} while (M_EnemySetPosition.x > P_Player->GetPosition().x - 1000.0f && M_EnemySetPosition.x < P_Player->GetPosition().x + 1000.0f);

			do
			{
				AngleZ = rand() % 381 - 190;
				M_EnemySetPosition.z = AngleZ * 100.0f;
			} while (M_EnemySetPosition.z > P_Player->GetPosition().z - 1000.0f && M_EnemySetPosition.z < P_Player->GetPosition().z + 1000.0f);

			P_Enemy = NewGO<Enemy>(0, "enemy");
			P_Enemy->SetPosition(M_EnemySetPosition);
			EnemyGenerate();
		}
	}
}