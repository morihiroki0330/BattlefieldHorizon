#pragma once

#include "geometry/AABB.h"

namespace nsK2EngineLow
{
	class RenderingEngine;
	class ModelRender : public IRender
	{
	public:
		void Init
		(
			const char* filePath,
			AnimationClip* animationClips = nullptr,
			int numAnimationClips = 0,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ
		);

		void InitForwardRendering(ModelInitData& initData);

		void Update();

//�`�揈��

		void Draw(RenderContext& rc);
		
		void OnRender(RenderContext& rc) override;

//���W�E��]�E�g��

		void SetTRS(const Vector3& pos, const Quaternion& rotation, const Vector3& scale)
		{
			SetPosition(pos);
			SetRotation(rotation);
			SetScale(scale);
		}

		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}

		void SetRotation(const Quaternion& rotation)
		{
			m_rotation = rotation;
		}

		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}

//���f��

		//���f���̎擾
		Model& GetModel()
		{
			return m_model;
		}

//�A�j���[�V����
		
		void InitAnimation
		(
			AnimationClip* animationClips,
			int numAnimationClips,
			EnModelUpAxis enModelUpAxis
		);

		void InitSkeleton(const char* filePath);

		void PlayAnimation(int animNo, float interpolareTime = 0.0f)
		{
			m_animation.Play(animNo, interpolareTime);
		}

		bool IsPlayAnimation() const
		{
			return m_animation.IsPlaying();
		}

		void SetAnimationSpeed(const float animationSpeed)
		{

		}

		Bone* GetBone(int boneNo) const
		{
			return m_skeleton.GetBone(boneNo);
		}

		int FindBoneID(const wchar_t* boneName)
		{
			return m_skeleton.FindBoneID(boneName);
		}
	private:

		void UpdaterWorldMatrixInModes();
		
//���f��

		Model m_model;
		Model m_forwardRenderModel;

		ModelInitData m_modelInitData;

//�A�j���[�V����

		Animation m_animation;

		AnimationClip* m_animationClips = nullptr;

		int m_numAnimationClips = 0;

		float m_animationSpeed = 1.0f;

		bool m_isUpdateAnimation = true;
		
		EnModelUpAxis m_enFbxUpAxis = enModelUpAxisZ;

//�X�P���g��

		Skeleton m_skeleton;

		Vector3 m_position = Vector3::Zero;			
		Quaternion m_rotation = Quaternion::Identity;	
		Vector3 m_scale = Vector3::One;				

		bool m_isEnableInstancingDraw = false;
	};
}

