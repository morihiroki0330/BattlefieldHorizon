#include "stdafx.h"
#include "Ui.h"
bool Ui::Start()
{
	//Back.Init("Assets/Sprite/Ui/BackGround.DDS", 1920.0f, 1080.0f, true);
	Back.Init("Assets/Sprite/Ui/Sample.DDS", 1920.0f, 1080.0f, true);
	return true;
}
void Ui::Update()
{
	Back.Update();
}
void Ui::Render(RenderContext& rc)
{
	Back.Draw(rc);
}