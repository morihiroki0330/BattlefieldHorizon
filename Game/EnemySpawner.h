#pragma once
class Enemy;
class EnemySpawner : public IGameObject
{
public:
	EnemySpawner();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_EnemySpawnerModel;

	Vector3 M_EnemySpawnerPosition;

	PhysicsStaticObject M_PhysicsStaticObject;

	int M_Level = 1;
};

