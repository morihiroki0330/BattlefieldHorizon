#pragma once
class GameCamera;
class GunSight : public IGameObject
{
public:
	GunSight();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GunSightTexture;

	GameCamera* P_GameCamera = nullptr;
};

