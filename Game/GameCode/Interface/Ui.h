#pragma once
/*
UIに表示するステータス
・プレイヤーのHP
・銃弾の弾薬〇
・銃の種類〇
・銃の標準〇
・スコアボード〇
・ミニマップ〇
・タイム〇
・現在のウェーブ〇
・残りエネミー数
・背景〇
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

