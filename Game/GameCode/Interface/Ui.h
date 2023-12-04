#pragma once
/*
UIに表示するステータス
・プレイヤーのHP
・銃弾の弾薬
・銃の種類
・銃の標準
・スコアボード
・ミニマップ
・タイム
・現在のウェーブ
*/
#include "DimensionalStorage/StructStorage.h"
class Ui : public IGameObject
{
public:

private:
	ClassPlayer S_Player;
};

