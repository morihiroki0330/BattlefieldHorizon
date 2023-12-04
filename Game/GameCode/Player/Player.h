#pragma once
#include "DimensionalStorage/StructStorage.h"
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void PlayerMove();
	void PlayerFall();

	void InitValue();

	const Vector3& GetPosition()
	{return S_Player.M_PlayerPosition;}
private:
	DataPlayerModel S_Player;

	ClassOperation S_Operation;
	ClassObject S_Object;
	ClassGun S_Gun;
};

