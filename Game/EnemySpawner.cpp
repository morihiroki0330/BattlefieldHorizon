#include "stdafx.h"
#include "EnemySpawner.h"
EnemySpawner::EnemySpawner()
{

}
void EnemySpawner::Update()
{

	M_EnemySpawnerModel.Update();
}
void EnemySpawner::Render(RenderContext& rc)
{
	M_EnemySpawnerModel.Draw(rc);
}