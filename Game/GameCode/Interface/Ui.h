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
class Ui : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender Back;
	ClassPlayer S_Player;
};

