#pragma once
/*
UI�ɕ\������X�e�[�^�X
�E�v���C���[��HP�Z
�E�e�e�̒e��Z
�E�e�̎�ށZ
�E�e�̕W���Z
�E�X�R�A�{�[�h�Z
�E�~�j�}�b�v
�E�^�C��
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
private:
	DataUi S_Ui;
	DataUiTexture S_UiTexture;
	
	ClassGame S_Game;
	ClassGun S_Gun;
	ClassPlayer S_Player;
	ClassEnemy S_Enemy;
	
	std::vector<Enemy*> P_Enemy;

	Level2DRender Level2D;

	int Count = 0;
	int Size = 0;
	int SizeX = 0;
	int SizeY = 0;
};

