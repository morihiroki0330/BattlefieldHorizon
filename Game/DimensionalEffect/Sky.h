#pragma once
enum EnSkyBoxType
{
	SkyBoxType_Morning,
	SkyBoxType_Noon,
	SkyBoxType_Night,
	SkyBoxType_Num
};
class Sky : public IGameObject
{
public:
	Sky();
	bool Start();
	void Update();
	void SetType(EnSkyBoxType type)
	{
		Type = type;
	}
	void Render(RenderContext& rc);
private:
	Texture M_Texture[5];
	const wchar_t* M_TextureFilePaths[5];
	ModelRender M_SkyBox;
	EnSkyBoxType Type = SkyBoxType_Morning;
};
