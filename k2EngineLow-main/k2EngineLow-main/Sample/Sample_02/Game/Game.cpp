#include "stdafx.h"
#include "Game.h"


void Game::InitSkeleton()
{
	m_skeleton.Init("Assets/modelData/unityChan.tks");
}
void Game::InitModel()
{
	ModelInitData initData;
	//tkm�t�@�C���̃t�@�C���p�X���w�肷��B
	initData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	//�V�F�[�_�[�t�@�C���̃t�@�C���p�X���w�肷��B
	initData.m_fxFilePath = "Assets/shader/model.fx";
	//�m���X�L�����b�V���p�̒��_�V�F�[�_�[�̃G���g���[�|�C���g���w�肷��B
	initData.m_vsEntryPointFunc = "VSMain";
	//�X�L�����b�V���p�̒��_�V�F�[�_�[�̃G���g���[�|�C���g���w��B
	initData.m_vsSkinEntryPointFunc = "VSSkinMain";
	//�X�P���g�����w�肷��B
	initData.m_skeleton = &m_skeleton;
	//���f���̏�������w�肷��B
	//3dsMax�ł̓f�t�H���gZ�A�b�v�ɂȂ��Ă��邪�A
	//���j�e�B�����̓A�j���[�V������Y�A�b�v�ɕύX����Ă���B
	initData.m_modelUpAxis = enModelUpAxisY;

	//�쐬�����������f�[�^�����ƂɃ��f��������������A
	m_model.Init(initData);
}

void Game::InitAnimation()
{
	//�A�j���[�V�����N���b�v�����[�h����B
	m_animationClipArray[enAnimClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClipArray[enAnimClip_Idle].SetLoopFlag(true);
	m_animationClipArray[enAnimClip_Run].Load("Assets/animData/walk.tka");
	m_animationClipArray[enAnimClip_Run].SetLoopFlag(true);
	//�A�j���[�V�������������B
	m_animation.Init(
		m_skeleton,			//�A�j���[�V�����𗬂����ރX�P���g���B
		m_animationClipArray,	//�A�j���[�V�����N���b�v�B
		enAnimClip_Num		//�A�j���[�V�����̐��B
	);
}

bool Game::Start()
{
	//�X�P���g�������[�h�B
	InitSkeleton();
	//���f�����������B
	InitModel();
	//�A�j���[�V�������������B
	InitAnimation();

	return true;
}

void Game::Update()
{
	// �A�j���[�V�����̐؂�ւ��B
	if (g_pad[0]->IsPress(enButtonA)) {
		m_animation.Play(enAnimClip_Idle, 0.2f);
	}
	if (g_pad[0]->IsPress(enButtonB)) {
		m_animation.Play(enAnimClip_Run, 0.2f);
	}
	// ��]
	m_rotation.AddRotationY(g_pad[0]->GetRStickXF() * 0.05f);

	// ���s�ړ�
	m_position.x += g_pad[0]->GetLStickXF();
	m_position.y += g_pad[0]->GetLStickYF();

	//�X�P���g�����X�V�B
	m_skeleton.Update(m_model.GetWorldMatrix());

	//�A�j���[�V������i�߂�B
	m_animation.Progress(g_gameTime->GetFrameDeltaTime());

	// ���[���h�s����X�V�B
	m_model.UpdateWorldMatrix(m_position, m_rotation, g_vec3One);
}
void Game::Render(RenderContext& rc)
{
	// �h���[�B
	m_model.Draw(rc);
}