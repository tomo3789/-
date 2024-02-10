#pragma once
class Game : public IGameObject
{
public:
	
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	// �X�P���g����������
	void InitSkeleton();
	// ���f�����������B
	void InitModel();
	// �A�j���[�V�������������B
	void InitAnimation();
private:
	// �A�j���[�V�����N���b�v�̔ԍ���\���񋓌^�B
	enum EnAnimationClip {
		enAnimClip_Idle,	// 0 : �ҋ@�A�j���[�V�����A
		enAnimClip_Run,		// 1 : ����A�j���[�V�����B
		enAnimClip_Num,		// 2 :�A�j���[�V�����N���b�v�̐��B
	};
	Model m_model;			// ���f��
	Skeleton m_skeleton;	// �X�P���g��
	Animation m_animation;	// �A�j���[�V����
	AnimationClip m_animationClipArray[enAnimClip_Num];	// �A�j���[�V�����N���b�v
	Vector3 m_position;		// ���W
	Quaternion m_rotation;	// ��]
};

