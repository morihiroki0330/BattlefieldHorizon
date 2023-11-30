#pragma once
class BattlefieldHorizon;
class DimensionalCollision;
class Mouse;
class GameResult : public IGameObject
{
public:
	GameResult();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;
	SpriteRender M_ResultButton;
	DimensionalCollision* P_Collision = nullptr;
	BattlefieldHorizon* P_Horizon = nullptr;
	Mouse* P_Mouse = nullptr;
};

