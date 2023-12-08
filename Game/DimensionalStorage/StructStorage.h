#pragma once
/*��������N���X�̃|�C���^*/
class BattlefieldHorizon;
struct ClassGame
{
	BattlefieldHorizon* P_Horizon = nullptr;
};

class GameTitle;
class GameResult;
class Sound;
class Ui;
struct ClassInterface
{
	GameTitle* P_GameTitle   = nullptr;
	GameResult* P_GameResult = nullptr;
	Sound* P_Sound           = nullptr;
	Ui* P_Ui                 = nullptr;
};

class Enemy;
class EnemySpawner;
struct ClassEnemy
{
	Enemy* P_Enemy               = nullptr;
	EnemySpawner* P_EnemySpawner = nullptr;
};

class Player;
struct ClassPlayer
{
	Player* P_Player             = nullptr;
};

class TileMap;
class GameCamera;
struct ClassObject
{
	TileMap* P_TileMap       = nullptr;
	GameCamera* P_GameCamera = nullptr;
};

class Gun;
class GunSight;
class GunSound;
class Bullet;
struct ClassGun
{
	Gun* P_Gun           = nullptr;
	GunSight* P_GunSight = nullptr;
	GunSound* P_GunSound = nullptr;
	Bullet* P_Bullet     = nullptr;
};

class DimensionalCollision;
struct ClassDimensionalElement
{
	DimensionalCollision* P_Collision = nullptr;
};

class Fade;
class Sky;
struct ClassDimensionalEffect
{
	Fade* P_Fade = nullptr;
	Sky* P_Sky   = nullptr;
};

class Mouse;
class Controller;
struct ClassOperation
{
	Mouse* P_Mouse           = nullptr;
	Controller* P_Controller = nullptr;
};

/*��������N���X�̃f�[�^*/

//�Q�[���^�C�g��
struct DataGameTitleGraphics
{
	SpriteRender M_BackGroundTexture;
	SpriteRender M_Cloud[10];
	SpriteRender M_TextTexture;

	Vector3 M_CloudPosition[10];
	Vector3 M_TextPosition = { 0.0f,300.0f,0.0f };

	int M_CloudCount;
	bool M_CloudFlag[10];
};
struct DataGameTitleButton
{
	SpriteRender M_StartButton;
	SpriteRender M_OptionButton;
	SpriteRender M_ExitButton;

	Vector3 M_StartButtonPosition  = { 0.0f , 100.0f  , 0.0f };
	Vector3 M_OptionButtonPosition = { 0.0f , -80.0f  , 0.0f };
	Vector3 M_ExitButtonPosition   = { 0.0f , -260.0f , 0.0f };

	bool M_StartFlag  = false;
	bool M_OptionFlag = false;
	bool M_ExitFlag   = false;
};

//�Q�[�����U���g
struct DataGameResultGraphics
{
	SpriteRender M_GameResultTexture;
};
struct DataGameResultButton
{
	SpriteRender M_ResultButton;
};

//�v���C���[
#include "physics/PhysicsGhostObject.h"
struct DataPlayer
{
	ModelRender M_PlayerModel;

	Vector3 M_PlayerPosition = { 0.0f , 500.0f , 0.0f };
	Vector3 M_PlayerSpeed    = { 0.0f , 0.0f   , 0.0f };
	Vector3 M_PlayerForward  = { 0.0f , 0.0f   , 0.0f };
	Vector3 M_PlayerRight    = { 0.0f , 0.0f   , 0.0f };

	CharacterController M_PlayerController;
	PhysicsGhostObject M_PlayerGhost;

	int M_PlayerHp = 100;
	
	bool M_CoolDownFlag = false;
	int M_CoolDownTime = 0;
	int M_CoolDownTimeFixed = 10;
};

//�Q�[���J����
struct DataCamera
{
	Vector3 M_CameraPosition = { 0.0f , 150.0f , 0.0f };
	Vector3 M_CameraTarget   = { 0.0f , 0.0f   , 4800000.0f };
	Vector2 M_MovePosition   = { 0.0f , 0.0f };

	int M_Angle = 0;

	const float M_CircleFication = 4800000.0f;
	const float M_MagniFication  = 10000.0f;
};

//�e�e
#include "physics/PhysicsGhostObject.h"
struct DataBullet
{
	ModelRender M_BulletModel;

	PhysicsGhostObject M_BulletGhost;

	Vector3 M_BulletPosition = { 0.0f , 0.0f , 0.0f };
	Vector3 M_BulletSpeed    = { 0.0f , 0.0f , 0.0f };

	float M_BuleetSpeedMagniFication = 100000.0f;

	int DeadTime = 0;
	int DeadTimeMax = 60;
};

//�e
struct DataGun
{
	bool M_CoolDownFlag = false;

	int M_CoolDownTime = 0;
	int M_CoolDownTimeFixed = 15;
	int M_BulletCount = 60;
	int M_BulletMaxCount = 60;
};

//�X�R�[�v
struct DataGunSight
{
	SpriteRender M_GunSightTexture;
};

//�G�̃X�|�i�[
struct DataEnemySpawner
{
	ModelRender M_EnemySpawnerModel;
	Vector3 M_EnemySpawnerPosition = { 0.0f,200.0f,0.0f };
	Vector3 M_EnemySetPosition = { 0.0f,500.0f,0.0f };

	int M_EnemyCount = 0;
	int M_EnemyCountMax = 1;
	int M_Level = 1;
	bool Flag = true;

	float AngleX = rand() % 381 - 190;
	float AngleZ = rand() % 381 - 190;
};

//�G
struct DataEnemy
{
	ModelRender M_EnemyModel;

	Vector3 M_EnemyPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_EnemySpeed    = { 0.0f,0.0f,0.0f };

	CharacterController M_EnemyController;

	int M_EnemyHp  = 1;
	int M_EnemyScore = 500;
	int M_CoolTime = 0;

	bool M_CoolFlag = false;
};

struct DataUi
{
	Vector4 BulletIn  = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 BulletOut = { 0.8f , 0.0f , 0.0f , 1.0f };
	int BulletCount;
	int BulletCount10;
	int BulletCount1;
	int BulletCountMemory;

	int WaveCount;
	int WaveCountMemory;

	int EnemyCount;
	int EnemyCountMemory;
	int EnemyCount100;
	int EnemyCount10;
	int EnemyCount1;

	int ScoreCount;
	int ScoreCountMemory;
	int ScoreCount10000000;
	int ScoreCount1000000;
	int ScoreCount100000;
	int ScoreCount10000;
	int ScoreCount1000;
	int ScoreCount100;
	int ScoreCount10;
	int ScoreCount1;

	int PlayerHp;
	int PlayerHpMemory;
};
struct DataUiTexture
{
	SpriteRender CanvasTexture;

	SpriteRender PlayerHpTexture;
	SpriteRender PlayerHpFrameTexture;

	SpriteRender EnemyCountTexture[3];
	SpriteRender EnemyIconTexture;

	SpriteRender WaveTexture;
	SpriteRender WaveFrameTexture;

	SpriteRender BulletCountTexture[2];
	SpriteRender GunFrameTexture;

	SpriteRender ScoreCountTexture[8];
	SpriteRender ScoreTexture;

	SpriteRender MiniMapFrameTexture;
	SpriteRender MiniMapPlayerTexture;
	SpriteRender MiniMapEnemyTexture;

	SpriteRender TimeTexture[5];
	void TextureInit()
	{
		CanvasTexture.Init("Assets/Sprite/Ui/Canvas.DDS", 1920.0f, 1080.0f, true);

		PlayerHpTexture.Init("Assets/Sprite/Ui/Hp/Hp.DDS", 280.0f, 80.0f, true);
		PlayerHpFrameTexture.Init("Assets/Sprite/Ui/Hp/HpFrame.DDS", 300.0f, 100.0f, true);

		BulletCountTexture[0].Init("Assets/Sprite/Ui/Count/0.DDS", 50.0f, 50.0f, true);
		BulletCountTexture[1].Init("Assets/Sprite/Ui/Count/0.DDS", 50.0f, 50.0f, true);
		GunFrameTexture.Init("Assets/Sprite/Ui/GunFrame.DDS", 300.0f, 100.0f, true);

		ScoreCountTexture[0].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		ScoreCountTexture[1].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		ScoreCountTexture[2].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		ScoreCountTexture[3].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		ScoreCountTexture[4].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		ScoreCountTexture[5].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		ScoreCountTexture[6].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		ScoreCountTexture[7].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		ScoreTexture.Init("Assets/Sprite/Ui/Score.DDS", 320.0f, 80.0f, true);

		WaveTexture.Init("Assets/Sprite/Ui/Wave/Wave1.DDS", 250.0f, 80.0f, true);
		WaveFrameTexture.Init("Assets/Sprite/Ui/Wave/WaveFrame.DDS", 300.0f, 100.0f, true);

		MiniMapFrameTexture.Init("Assets/Sprite/Ui/MiniMap/MiniMap.DDS", 380.0f, 380.0f, true);
		MiniMapPlayerTexture.Init("Assets/Sprite/Ui/MiniMap/MiniMapPlayer.DDS", 15.0f, 15.0f, true);
		MiniMapEnemyTexture.Init("Assets/Sprite/Ui/MiniMap/MiniMapEnemy.DDS", 15.0f, 15.0f, true);

		EnemyCountTexture[0].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		EnemyCountTexture[1].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		EnemyCountTexture[2].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		EnemyIconTexture.Init("Assets/Sprite/Ui/EnemyCounter/EnemyIcon.DDS", 150.0f, 75.0f, true);
	}
	void TextureUpdate()
	{
		CanvasTexture.Update();

		PlayerHpTexture.Update();
		PlayerHpFrameTexture.Update();

		EnemyCountTexture[0].Update();
		EnemyCountTexture[1].Update();
		EnemyCountTexture[2].Update();
		EnemyIconTexture.Update();

		WaveTexture.Update();
		WaveFrameTexture.Update();
		
		BulletCountTexture[0].Update();
		BulletCountTexture[1].Update();
		GunFrameTexture.Update();

		ScoreCountTexture[0].Update();
		ScoreCountTexture[1].Update();
		ScoreCountTexture[2].Update();
		ScoreCountTexture[3].Update();
		ScoreCountTexture[4].Update();
		ScoreCountTexture[5].Update();
		ScoreCountTexture[6].Update();
		ScoreCountTexture[7].Update();
		ScoreTexture.Update();

		MiniMapFrameTexture.Update();
		MiniMapPlayerTexture.Update();
		MiniMapEnemyTexture.Update();
	}
	void TextureRender(RenderContext& rc)
	{
		CanvasTexture.Draw(rc);

		PlayerHpTexture.Draw(rc);
		PlayerHpFrameTexture.Draw(rc);
		
		BulletCountTexture[0].Draw(rc);
		BulletCountTexture[1].Draw(rc);
		GunFrameTexture.Draw(rc);
		
		WaveTexture.Draw(rc);
		WaveFrameTexture.Draw(rc);

		MiniMapFrameTexture.Draw(rc);
		MiniMapPlayerTexture.Draw(rc);
		MiniMapEnemyTexture.Draw(rc);

		EnemyCountTexture[0].Draw(rc);
		EnemyCountTexture[1].Draw(rc);
		EnemyCountTexture[2].Draw(rc);
		EnemyIconTexture.Draw(rc);

		ScoreCountTexture[0].Draw(rc);
		ScoreCountTexture[1].Draw(rc);
		ScoreCountTexture[2].Draw(rc);
		ScoreCountTexture[3].Draw(rc);
		ScoreCountTexture[4].Draw(rc);
		ScoreCountTexture[5].Draw(rc);
		ScoreCountTexture[6].Draw(rc);
		ScoreCountTexture[7].Draw(rc);
		ScoreTexture.Draw(rc);
	}
};