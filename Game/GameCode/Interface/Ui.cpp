#include "stdafx.h"
#include "Ui.h"
#include "GameCode/GameCode.h"
bool Ui::Start()
{
	S_UiTexture.TextureInit();

	Level2D.Init("Assets/Sprite/Level2D/Ui.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("Canvas") == true)
		{
			S_UiTexture.CanvasTexture.SetPosition(objData.position);
			return true;
		}
			
	if (objData.EqualObjectName("MiniMap") == true)
	{
		S_UiTexture.MiniMapFrameTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("MiniMapPlayer") == true)
	{
		S_UiTexture.MiniMapPlayerTexture.SetPosition(objData.position);
		return false;
	}

	if (objData.EqualObjectName("WaveFrame") == true)
	{
		S_UiTexture.WaveFrameTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("HpFrame") == true)
	{
		S_UiTexture.PlayerHpFrameTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("GunFrame") == true)
	{
		S_UiTexture.GunFrameTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("EnemyIcon") == true)
	{
		S_UiTexture.EnemyIconTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("Score") == true)
	{
		S_UiTexture.ScoreTexture.SetPosition(objData.position);
		return true;
	}
		
	if (objData.EqualObjectName("Minute") == true)
	{
		for (int i = 0; i < sizeof(S_UiTexture.MinuteTexture) / sizeof(S_UiTexture.MinuteTexture[0]); i++)
		{
			S_UiTexture.MinuteTexture[i].SetPosition(objData.position);
			objData.position.x += 30.0f;
		}
		return true;
	}
	if (objData.EqualObjectName("Second") == true)
	{
		for (int i = 0; i < sizeof(S_UiTexture.SecondTexture) / sizeof(S_UiTexture.SecondTexture[0]); i++)
		{
			S_UiTexture.SecondTexture[i].SetPosition(objData.position);
			objData.position.x += 30.0f;
		}
		return true;
	}

	if (objData.EqualObjectName("Wave") == true)
	{
		S_UiTexture.WaveTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("Hp") == true)
	{
		S_UiTexture.PlayerHpTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("BulletCount") == true)
	{
		for (int i = 0; i < sizeof(S_UiTexture.BulletCountTexture) / sizeof(S_UiTexture.BulletCountTexture[0]); i++)
		{
			S_UiTexture.BulletCountTexture[i].SetPosition(objData.position);
			objData.position.x += 30.0f;
		}
		return true;
	}
	if (objData.EqualObjectName("EnemyCount") == true)
	{
		for (int i = 0; i < sizeof(S_UiTexture.EnemyCountTexture) / sizeof(S_UiTexture.EnemyCountTexture[0]); i++)
		{
			S_UiTexture.EnemyCountTexture[i].SetPosition(objData.position);
			objData.position.x += 40.0f;
		}
		return true;
	}
	if (objData.EqualObjectName("ScoreCount") == true)
	{
		for (int i = 0;i < sizeof(S_UiTexture.ScoreCountTexture) / sizeof(S_UiTexture.ScoreCountTexture[0]); i++)
		{
			S_UiTexture.ScoreCountTexture[i].SetPosition(objData.position);
			objData.position.x += 40.0f;
		}		
		return true;
	}						
		return false;
	});

	S_Game.P_Horizon = FindGO<BattlefieldHorizon>("horizon");
	S_Gun.P_Gun = FindGO<Gun>("gun");
	S_Enemy.P_EnemySpawner = FindGO<EnemySpawner>("enemyspawner");
	S_Player.P_Player = FindGO<Player>("player");
	return true;
}
void Ui::Update()
{
	P_Enemy = FindGOs<Enemy>("enemy");
	Wave();
	BulletCount();
	EnemyCount();
	ScoreCount();
	PlayerHp();
	MiniMap();
	Time();
	S_UiTexture.TextureUpdate();
}
void Ui::Render(RenderContext& rc)
{
	S_UiTexture.TextureRender(rc);
	Size = sizeof(P_Enemy) / sizeof(P_Enemy[0]);
	Size--;
	for (int i = 0; i < Size; i++)
	{
		Vector3 Posa = { ((-S_Player.P_Player->GetPosition().x / 10) + (P_Enemy[i]->GetPosition().x / 10)) + 770.0f , ((-S_Player.P_Player->GetPosition().z / 10) + (P_Enemy[i]->GetPosition().z / 10)) + 350.0f , 0.0f };
		if ((abs)(S_UiTexture.MiniMapPlayerTexture.GetPosition().x - Posa.x) < 190.0f && (abs)(S_UiTexture.MiniMapPlayerTexture.GetPosition().y - Posa.y) < 190.0f)
		{S_UiTexture.MiniMapEnemyTexture[i].Draw(rc); }
		Count++;
	}
}

void Ui::Wave()
{
	S_Ui.WaveCount = S_Game.P_Horizon->GetWave();
	if (S_Ui.WaveCount != S_Ui.WaveCountMemory)
	{
		switch (S_Ui.WaveCount)
		{
		case 1:
			S_UiTexture.WaveTexture.TextureSet("Assets/Sprite/Ui/Wave/Wave1.DDS");
			break;
		case 2:
			S_UiTexture.WaveTexture.TextureSet("Assets/Sprite/Ui/Wave/Wave2.DDS");
			break;
		case 3:
			S_UiTexture.WaveTexture.TextureSet("Assets/Sprite/Ui/Wave/Wave3.DDS");
			break;
		}
	}
	S_Ui.WaveCountMemory = S_Ui.WaveCount;
}
void Ui::BulletCount()
{
	S_Ui.BulletCount = S_Gun.P_Gun->GetBulletCount();
	if (S_Ui.BulletCount != S_Ui.BulletCountMemory)
	{
		int Count = 0;
		int BulletCount = 0;

		S_Ui.BulletCount10 = (S_Ui.BulletCount / 10) % 10;
		S_Ui.BulletCount1 = (S_Ui.BulletCount % 10);

		for (int i = 10; i != 1 / 10; i /= 10)
		{
			switch (i)
			{
			case 1:
				BulletCount = S_Ui.BulletCount1;
				break;
			case 10:
				BulletCount = S_Ui.BulletCount10;
				break;
			}

			switch (BulletCount)
			{
			case 0:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/0.DDS");
				break;
			case 1:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/1.DDS");
				break;
			case 2:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/2.DDS");
				break;
			case 3:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/3.DDS");
				break;
			case 4:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/4.DDS");
				break;
			case 5:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/5.DDS");
				break;
			case 6:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/6.DDS");
				break;
			case 7:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/7.DDS");
				break;
			case 8:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/8.DDS");
				break;
			case 9:
				S_UiTexture.BulletCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/9.DDS");
				break;
			}
			Count++;
		}
	}

	S_Ui.BulletCountMemory = S_Ui.BulletCount;

	if (S_Ui.BulletCount == 0)
	{
		S_UiTexture.BulletCountTexture[0].SetMulColor(S_Ui.BulletOut);
		S_UiTexture.BulletCountTexture[1].SetMulColor(S_Ui.BulletOut);
		S_UiTexture.GunFrameTexture.SetMulColor(S_Ui.BulletOut);
	}else {
		S_UiTexture.BulletCountTexture[0].SetMulColor(S_Ui.BulletIn);
		S_UiTexture.BulletCountTexture[1].SetMulColor(S_Ui.BulletIn);
		S_UiTexture.GunFrameTexture.SetMulColor(S_Ui.BulletIn);
	}
}
void Ui::EnemyCount()
{
	S_Ui.EnemyCount = S_Enemy.P_EnemySpawner->GetEnemyCount();
	if (S_Ui.EnemyCount != S_Ui.EnemyCountMemory)
	{
		int Count = 0;
		int EnemyCount = 0;

		S_Ui.EnemyCount100 = (S_Ui.EnemyCount / 100) % 10;
		S_Ui.EnemyCount10  = (S_Ui.EnemyCount / 10)  % 10;
		S_Ui.EnemyCount1   = (S_Ui.EnemyCount % 10);

		for (int i = 100 ; i != 1 / 10; i /= 10)
		{
			switch (i)
			{
			case 1:
				EnemyCount = S_Ui.EnemyCount1;
				break;
			case 10:
				EnemyCount = S_Ui.EnemyCount10;
				break;
			case 100:
				EnemyCount = S_Ui.EnemyCount100;
				break;
			}

			switch (EnemyCount)
			{
			case 0:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/0.DDS");
				break;
			case 1:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/1.DDS");
				break;
			case 2:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/2.DDS");
				break;
			case 3:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/3.DDS");
				break;
			case 4:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/4.DDS");
				break;
			case 5:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/5.DDS");
				break;
			case 6:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/6.DDS");
				break;
			case 7:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/7.DDS");
				break;
			case 8:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/8.DDS");
				break;
			case 9:
				S_UiTexture.EnemyCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/9.DDS");
				break;
			}
			Count++;
		}
	}
	S_Ui.EnemyCountMemory = S_Ui.EnemyCount;
}
void Ui::ScoreCount()
{
	S_Ui.ScoreCount = S_Game.P_Horizon->GetScore();
	if (S_Ui.ScoreCount != S_Ui.ScoreCountMemory)
	{
		int Count = 0;
		int ScoreCount = 0;

		S_Ui.ScoreCount10000000 = (S_Ui.ScoreCount / 10000000);
		S_Ui.ScoreCount1000000  = (S_Ui.ScoreCount / 1000000) % 10;
		S_Ui.ScoreCount100000   = (S_Ui.ScoreCount / 100000) % 10;
		S_Ui.ScoreCount10000    = (S_Ui.ScoreCount / 10000) % 10;
		S_Ui.ScoreCount1000     = (S_Ui.ScoreCount / 1000) % 10;
		S_Ui.ScoreCount100      = (S_Ui.ScoreCount / 100) % 10;
		S_Ui.ScoreCount10       = (S_Ui.ScoreCount / 10) % 10;
		S_Ui.ScoreCount1        = (S_Ui.ScoreCount % 10);

		for (int i = 10000000; i != 1 / 10; i /= 10)
		{
			switch (i)
			{
			case 1:
				ScoreCount = S_Ui.ScoreCount1;
				break;
			case 10:
				ScoreCount = S_Ui.ScoreCount10;
				break;
			case 100:
				ScoreCount = S_Ui.ScoreCount100;
				break;
			case 1000:
				ScoreCount = S_Ui.ScoreCount1000;
				break;
			case 10000:
				ScoreCount = S_Ui.ScoreCount10000;
				break;
			case 100000:
				ScoreCount = S_Ui.ScoreCount100000;
				break;
			case 1000000:
				ScoreCount = S_Ui.ScoreCount1000000;
				break;
			case 10000000:
				ScoreCount = S_Ui.ScoreCount10000000;
				break;
			}

			switch (ScoreCount)
			{
			case 0:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/0.DDS");
				break;
			case 1:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/1.DDS");
				break;
			case 2:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/2.DDS");
				break;
			case 3:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/3.DDS");
				break;
			case 4:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/4.DDS");
				break;
			case 5:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/5.DDS");
				break;
			case 6:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/6.DDS");
				break;
			case 7:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/7.DDS");
				break;
			case 8:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/8.DDS");
				break;
			case 9:
				S_UiTexture.ScoreCountTexture[Count].TextureSet("Assets/Sprite/Ui/Count/9.DDS");
				break;
			}
			Count++;
		}
	}
	S_Ui.ScoreCountMemory = S_Ui.ScoreCount;
}
void Ui::PlayerHp()
{
	S_Ui.PlayerHp = S_Player.P_Player->GetPlayerHp();
	if (S_Ui.PlayerHp != S_Ui.PlayerHpMemory)
	{
		if (S_Ui.PlayerHp >= 0.66 * 100)
		{
			S_UiTexture.PlayerHpTexture.SetMulColor({ 0.0f,1.0f,0.0f,1.0f });//óŒ
		}else {
			if (S_Ui.PlayerHp >= 0.33 * 100)
			{
				S_UiTexture.PlayerHpTexture.SetMulColor({ 1.0f,1.0f,0.0f,1.0f });//â©
			}else {
				if (S_Ui.PlayerHp >= 0.0 * 100)
				{
					S_UiTexture.PlayerHpTexture.SetMulColor({ 1.0f,0.0f,0.0f,1.0f });//ê‘
				}
			}
		}
	}
	S_Ui.PlayerHpMemory = S_Ui.PlayerHp;
}
void Ui::MiniMap()
{
	Size = sizeof(P_Enemy) / sizeof(P_Enemy[0]);
	Size--;
	for (int i = 0; i < Size; i++)
	{
		Vector3 Pos = { ((-S_Player.P_Player->GetPosition().x / 10) + (P_Enemy[i]->GetPosition().x / 10)) + 770.0f , ((-S_Player.P_Player->GetPosition().z / 10) + (P_Enemy[i]->GetPosition().z / 10)) + 350.0f , 0.0f };
		S_UiTexture.MiniMapEnemyTexture[i].SetPosition(Pos);
	}
}
void Ui::Time()
{
	S_Ui.Comma++;
	if (S_Ui.Comma >= 60)
	{
		S_Ui.Second++;
		S_Ui.Comma = 0;
	}
	if (S_Ui.Second >= 60)
	{
		S_Ui.Minute++;
		S_Ui.Second = 0;
	}
}