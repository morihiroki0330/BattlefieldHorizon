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
			S_UiPosition.CanvasPosition = objData.position;
			S_UiTexture.CanvasTexture.SetPosition(S_UiPosition.CanvasPosition);
			return true;
		}else {
			if (objData.EqualObjectName("GunFrame") == true)
			{
				S_UiPosition.GunFramePosition = objData.position;
				S_UiTexture.GunFrameTexture.SetPosition(S_UiPosition.GunFramePosition);
				return true;
			}else {
				if (objData.EqualObjectName("HpFrame") == true)
				{
					S_UiPosition.PlayerHpFramePosition = objData.position;
					S_UiTexture.PlayerHpFrameTexture.SetPosition(S_UiPosition.PlayerHpFramePosition);
					return true;
				}else {
					if (objData.EqualObjectName("WaveFrame") == true)
					{
						S_UiPosition.WaveFramePosition = objData.position;
						S_UiTexture.WaveFrameTexture.SetPosition(S_UiPosition.WaveFramePosition);
						return true;
					}else {
						if (objData.EqualObjectName("Wave") == true)
						{
							S_UiPosition.WavePosition = objData.position;
							S_UiTexture.WaveTexture.SetPosition(S_UiPosition.WavePosition);
							return true;
						}else {
							if (objData.EqualObjectName("MiniMap") == true)
							{
								S_UiPosition.MiniMapFramePosition = objData.position;
								S_UiTexture.MiniMapFrameTexture.SetPosition(S_UiPosition.MiniMapFramePosition);
								return true;
							}else {
								if (objData.EqualObjectName("EnemyIcon") == true)
								{
									S_UiPosition.EnemyIconPosition = objData.position;
									S_UiTexture.EnemyIconTexture.SetPosition(S_UiPosition.EnemyIconPosition);
									return true;
								}else {
									if (objData.EqualObjectName("Score") == true)
									{
										S_UiPosition.ScorePosition = objData.position;
										S_UiTexture.ScoreTexture.SetPosition(S_UiPosition.ScorePosition);
										return true;
									}
								}
							}
						}
					}
				}
			}
		}

		if (objData.EqualObjectName("BulletCount10") == true)
		{
			S_UiPosition.BulletCountPosition[0] = objData.position;
			S_UiTexture.BulletCountTexture[0].SetPosition(S_UiPosition.BulletCountPosition[0]);
			return true;
		}else {
			if (objData.EqualObjectName("BulletCount1") == true)
			{
				S_UiPosition.BulletCountPosition[1] = objData.position;
				S_UiTexture.BulletCountTexture[1].SetPosition(S_UiPosition.BulletCountPosition[1]);
				return true;
			}else {
				if (objData.EqualObjectName("EnemyCount100") == true)
				{
					S_UiPosition.EnemyCountPosition[0] = objData.position;
					S_UiTexture.EnemyCountTexture[0].SetPosition(S_UiPosition.EnemyCountPosition[0]);
				}else {
					if (objData.EqualObjectName("EnemyCount10") == true)
					{
						S_UiPosition.EnemyCountPosition[1] = objData.position;
						S_UiTexture.EnemyCountTexture[1].SetPosition(S_UiPosition.EnemyCountPosition[1]);
					}else {
						if (objData.EqualObjectName("EnemyCount1") == true)
						{
							S_UiPosition.EnemyCountPosition[2] = objData.position;
							S_UiTexture.EnemyCountTexture[2].SetPosition(S_UiPosition.EnemyCountPosition[2]);
						}
					}
				}
			}
		}

		if (objData.EqualObjectName("ScoreCount10000000") == true)
		{
			S_UiPosition.ScoreCountPosition[0] = objData.position;
			S_UiTexture.ScoreCountTexture[0].SetPosition(S_UiPosition.ScoreCountPosition[0]);
			return true;
		}else {
			if (objData.EqualObjectName("ScoreCount1000000") == true)
			{
				S_UiPosition.ScoreCountPosition[1] = objData.position;
				S_UiTexture.ScoreCountTexture[1].SetPosition(S_UiPosition.ScoreCountPosition[1]);
				return true;
			}else {
				if (objData.EqualObjectName("ScoreCount100000") == true)
				{
					S_UiPosition.ScoreCountPosition[2] = objData.position;
					S_UiTexture.ScoreCountTexture[2].SetPosition(S_UiPosition.ScoreCountPosition[2]);
				}else {
					if (objData.EqualObjectName("ScoreCount10000") == true)
					{
						S_UiPosition.ScoreCountPosition[3] = objData.position;
						S_UiTexture.ScoreCountTexture[3].SetPosition(S_UiPosition.ScoreCountPosition[3]);
					}else {
						if (objData.EqualObjectName("ScoreCount1000") == true)
						{
							S_UiPosition.ScoreCountPosition[4] = objData.position;
							S_UiTexture.ScoreCountTexture[4].SetPosition(S_UiPosition.ScoreCountPosition[4]);
						}else {
							if (objData.EqualObjectName("ScoreCount100") == true)
							{
								S_UiPosition.ScoreCountPosition[5] = objData.position;
								S_UiTexture.ScoreCountTexture[5].SetPosition(S_UiPosition.ScoreCountPosition[5]);
							}else {
								if (objData.EqualObjectName("ScoreCount10") == true)
								{
									S_UiPosition.ScoreCountPosition[6] = objData.position;
									S_UiTexture.ScoreCountTexture[6].SetPosition(S_UiPosition.ScoreCountPosition[6]);
								}else {
									if (objData.EqualObjectName("ScoreCount1") == true)
									{
										S_UiPosition.ScoreCountPosition[7] = objData.position;
										S_UiTexture.ScoreCountTexture[7].SetPosition(S_UiPosition.ScoreCountPosition[7]);
									}
								}
							}
						}
					}
				}
			}
		}
		return false;
	});

	S_Game.P_Horizon = FindGO<BattlefieldHorizon>("horizon");
	S_Gun.P_Gun = FindGO<Gun>("gun");
	S_Enemy.P_EnemySpawner = FindGO<EnemySpawner>("enemyspawner");
	S_Game.P_Horizon = FindGO<BattlefieldHorizon>("horizon");
	return true;
}
void Ui::Update()
{
	Wave();
	BulletCount();
	EnemyCount();
	ScoreCount();

	S_UiTexture.TextureUpdate();
}
void Ui::Render(RenderContext& rc)
{
	S_UiTexture.TextureRender(rc);
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
		switch (S_Ui.BulletCount / 10)
		{
		case 0:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/0.DDS");
			break;
		case 1:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/1.DDS");
			break;
		case 2:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/2.DDS");
			break;
		case 3:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/3.DDS");
			break;
		case 4:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/4.DDS");
			break;
		case 5:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/5.DDS");
			break;
		case 6:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/6.DDS");
			break;
		case 7:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/7.DDS");
			break;
		case 8:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/8.DDS");
			break;
		case 9:
			S_UiTexture.BulletCountTexture[0].TextureSet("Assets/Sprite/Ui/Count/9.DDS");
			break;
		}


		switch (S_Gun.P_Gun->GetBulletCount() - ((S_Ui.BulletCount / 10) * 10))
		{
		case 0:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/0.DDS");
			break;
		case 1:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/1.DDS");
			break;
		case 2:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/2.DDS");
			break;
		case 3:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/3.DDS");
			break;
		case 4:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/4.DDS");
			break;
		case 5:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/5.DDS");
			break;
		case 6:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/6.DDS");
			break;
		case 7:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/7.DDS");
			break;
		case 8:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/8.DDS");
			break;
		case 9:
			S_UiTexture.BulletCountTexture[1].TextureSet("Assets/Sprite/Ui/Count/9.DDS");
			break;
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