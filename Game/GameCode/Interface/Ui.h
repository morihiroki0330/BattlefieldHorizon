#pragma once
/*
UI�ɕ\������X�e�[�^�X
�E�v���C���[��HP�Z
�E�e�e�̒e��Z
�E�e�̎�ށZ
�E�e�̕W���Z
�E�X�R�A�{�[�h�Z
�E�~�j�}�b�v�Z
�E�^�C���Z
�E���݂̃E�F�[�u�Z
�E�c��G�l�~�[���Z
�E�w�i�Z
*/
#include "DimensionalStorage/StructStorage.h"
#include "level2D/Level2DRender.h"
class Ui : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Wave();
	void BulletCount();
	void EnemyCount();
	void ScoreCount();
	void PlayerHp();
	void Time();
	void MiniMap();

	void NumberTexture(SpriteRender& Sprite, int Number);
private:
	DataUi S_Ui;
	
	ClassGame S_Game;
	ClassGun S_Gun;
	ClassPlayer S_Player;
	ClassEnemy S_Enemy;
	ClassObject S_Object;
	
	std::vector<Enemy*> P_Enemy;

	Level2DRender Level2D;

	FontRender FX;
	wchar_t M_X[256];

	int Count = 0;
};

