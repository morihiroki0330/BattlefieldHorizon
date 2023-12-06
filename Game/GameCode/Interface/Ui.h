#pragma once
/*
UI�ɕ\������X�e�[�^�X
�E�v���C���[��HP
�E�e�e�̒e��Z
�E�e�̎�ށZ
�E�e�̕W���Z
�E�X�R�A�{�[�h�Z
�E�~�j�}�b�v�Z
�E�^�C���Z
�E���݂̃E�F�[�u�Z
�E�c��G�l�~�[��
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
private:
	DataUi S_Ui;
	DataUiTexture S_UiTexture;
	DataUiPosition S_UiPosition;
	
	ClassGame S_Game;
	ClassGun S_Gun;
	ClassPlayer S_Player;
	ClassEnemy S_Enemy;

	Level2DRender Level2D;
};

