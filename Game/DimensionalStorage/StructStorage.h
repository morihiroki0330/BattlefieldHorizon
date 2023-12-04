#pragma once
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
class EnemyStatus;
class EnemySpawner;
struct ClassEnemy
{
	Enemy* P_Enemy               = nullptr;
	EnemyStatus* P_EnemyStatus   = nullptr;
	EnemySpawner* P_EnemySpawner = nullptr;
};

class Player;
class PlayerStatus;
struct ClassPlayer
{
	Player* P_Player             = nullptr;
	PlayerStatus* P_PlayerStatus = nullptr;
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

//ゲームタイトル
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

//ゲームリザルト
struct DataGameResultGraphics
{
	SpriteRender M_GameResultTexture;
};
struct DataGameResultButton
{
	SpriteRender M_ResultButton;
};


//プレイヤー
struct DataPlayerModel
{
	ModelRender M_PlayerModel;

	Vector3 M_PlayerPosition = { 0.0f , 500.0f , 0.0f };
	Vector3 M_PlayerSpeed    = { 0.0f , 0.0f   , 0.0f };
	Vector3 M_PlayerForward  = { 0.0f , 0.0f   , 0.0f };
	Vector3 M_PlayerRight    = { 0.0f , 0.0f   , 0.0f };

	CharacterController M_PlayerController;
};
struct DataPlayerStatus
{

};

//ゲームカメラ
struct DataCamera
{
	Vector3 M_CameraPosition = { 0.0f , 150.0f , 0.0f };
	Vector3 M_CameraTarget   = { 0.0f , 0.0f   , 4800000.0f };
	Vector2 M_MovePosition   = { 0.0f , 0.0f };

	int M_Angle = 0;

	const float M_CircleFication = 4800000.0f;
	const float M_MagniFication  = 10000.0f;
};

//銃弾
#include "physics/PhysicsGhostObject.h"
struct DataBullet
{
	ModelRender M_BulletModel;

	PhysicsGhostObject M_BulletGhost;

	Vector3 M_BulletPosition = { 0.0f , 0.0f , 0.0f };
	Vector3 M_BulletSpeed    = { 0.0f , 0.0f , 0.0f };

	float M_BuleetSpeedMagniFication = 50000.0f;

	int DeadTime = 0;
};

//銃
struct DataGun
{
	bool M_CoolDownFlag = false;

	int M_CoolDownTime = 0;
	int M_CoolDownTimeFixed = 30;
};

//スコープ
struct DataGunSight
{
	SpriteRender M_GunSightTexture;
};

//敵のスポナー
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

//敵
struct DataEnemy
{
	ModelRender M_EnemyModel;

	Vector3 M_EnemyPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_EnemySpeed    = { 0.0f,0.0f,0.0f };

	CharacterController M_EnemyController;

	int M_EnemyHp  = 2;
	int M_CoolTime = 0;

	bool M_CoolFlag = false;
};

struct DataUi
{
	SpriteRender Back;
};