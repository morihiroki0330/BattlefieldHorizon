#pragma once
/*
UIに表示するステータス
・プレイヤーのHP〇
・銃弾の弾薬〇
・銃の種類〇
・銃の標準〇
・スコアボード〇
・ミニマップ
・タイム
・現在のウェーブ〇
・残りエネミー数〇
・背景〇
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

