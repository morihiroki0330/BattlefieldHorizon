#pragma once
namespace nsK2EngineLow
{
	class RenderingEngine;

	class SpriteRender : public IRender
	{
	public:
		//������
		//�����F�i�t�@�C���p�X�A�摜�̉����A�摜�̏c���A�����������j
		void Init
		(
			const char* Sprite,
			const float w,
			const float h,
			bool ColorOut = false,
			bool ColorChange = false,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		void WeatherInit
		(
			const char* Sprite,
			const float w = 1920.0f,
			const float h = 1080.0f,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		void MiniMapInit
		(
			SpriteInitData InitData,
			AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans
		);

		//�X�V
		void Update()
		{
			m_sprite.Update
			(
				m_position,
				m_rotation,
				m_scale,
				m_pivot
			);
		}

		//�`��
		void Draw(RenderContext& rc);

		//���W�E��]�E�g��

			//���W�̐ݒ�
		void SetPosition(const Vector3& pos)
		{m_position = pos;}
		void SetPositionX(const Vector3& pos)
		{m_position.x = pos.x;}
		void SetPositionY(const Vector3& pos)
		{m_position.y = pos.y;}
		void SetPositionZ(const Vector3& pos)
		{m_position.z = pos.z;}

		//���W�̎擾
		const Vector3& GetPosition() const
		{return m_position;}

		const Vector2& GetWideAndHeight() const
		{return M_WideAndHeight;}

		//��]�̐ݒ�
		void SetRotation(const Quaternion& rot)
		{m_rotation = rot;}

		//��]�̎擾
		const Quaternion& GetRotation() const
		{return m_rotation;}

		//�g�嗦�̐ݒ�
		void SetScale(const Vector3 scale)
		{m_scale = scale;}

		//���W�̎擾
		const Vector3& GetScale() const
		{return m_scale;}

		//�s�{�b�g�̐ݒ�
		void SetPivot(const Vector2& pivot)
		{m_pivot = pivot;}

		//�s�{�b�g�̎擾
		const Vector2& GetPivot() const
		{return m_pivot;}

		//��Z�J���[�̐ݒ�
		void SetMulColor(const Vector4& mulColor)
		{m_sprite.SetMulColor(mulColor);}

		//��Z�J���[�̎擾
		const Vector4& GetMulColor() const
		{return m_sprite.GetMulColor();}

		void OnRender2D(RenderContext& rc) override;

		bool GetInitFlag()
		{return M_InitFlag;}

		//�摜�ϊ�

		void TextureSet(const char* Sprite);
	
	private:
		//�X�v���C�g
		Texture M_Texture;
		const wchar_t* M_TextureFilePath;
		Sprite m_sprite;
		SpriteInitData InitData;
		//���W
		Vector3 m_position = Vector3::Zero;

		//��]
		Quaternion m_rotation = Quaternion::Identity;

		//�g�嗦
		Vector3 m_scale = Vector3::One;

		//�s�{�b�g
		Vector2 m_pivot = Sprite::DEFAULT_PIVOT;

		bool M_InitFlag = false;

		Vector2 M_WideAndHeight;
	};
}



