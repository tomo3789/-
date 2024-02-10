#include "stdafx.h"
#include "Background.h"

bool Background::Start()
{
	ModelInitData initData;
	initData.m_tkmFilePath = "Assets/modelData/bg/bg.tkm";
	// �V�F�[�_�[�t�@�C���̃t�@�C���p�X���w�肷��B
	initData.m_fxFilePath = "Assets/shader/model.fx";
	// ���_�V�F�[�_�[�̃G���g���[�|�C���g
	initData.m_vsEntryPointFunc = "VSMain";
	m_model.Init(initData);

	// �ÓI�����I�u�W�F�N�g���쐬�B
	m_physicsStaticObject.CreateFromModel(m_model, m_model.GetWorldMatrix());

	return true;
}
void Background::Update()
{

}
void Background::Render(RenderContext& rc)
{
	m_model.Draw(rc);
}