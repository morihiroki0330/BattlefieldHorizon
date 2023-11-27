#pragma once
class GameCamera;
class Player;
class Bullet : public IGameObject
{
public:
	Bullet();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move()
	{
		M_BulletPosition.x += M_BulletSpeed.x;
		M_BulletPosition.y += M_BulletSpeed.y;
		M_BulletPosition.z += M_BulletSpeed.z;
	}
private:
	ModelRender M_BulletModel;

	Vector3 M_BulletPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_BulletSpeed    = { 0.0f,0.0f,0.0f };

	float M_BuleetSpeedMagniFication = 50000.0f;

	GameCamera* P_GameCamera = nullptr;
	Player* P_Player         = nullptr;
};

