#pragma once
//ステージは19000.0f*19000.0f
#include "DimensionalStorage/StructStorage.h"
class BattlefieldHorizon : public IGameObject
{
public:
	BattlefieldHorizon();
	~BattlefieldHorizon();
	bool Start();
	void Update();
	void Create(int Number);
	
	void Reset();
	void ClearFlag()
	{M_ClearFlag = true;}
private:
	ClassInterface S_Interface;
	ClassPlayer S_Player;
	ClassEnemy S_Enemy;
	ClassObject S_Object;

	ClassDimensionalEffect S_Effect;
	ClassDimensionalElement S_Element;

	bool Clear = false;
	bool M_ClearFlag = false;
};

