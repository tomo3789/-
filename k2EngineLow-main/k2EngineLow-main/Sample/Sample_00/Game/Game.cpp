#include "stdafx.h"
#include "Game.h"


bool Game::Start()
{
	// ���f�������������邽�߂̏���ݒ�B
	ModelInitData initData;
	//tkm�t�@�C���̃t�@�C���p�X���w�肷��B
	initData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	//�V�F�[�_�[�t�@�C���̃t�@�C���p�X���w�肷��B
	initData.m_fxFilePath = "Assets/shader/model.fx";

	//�쐬�����������f�[�^�����ƂɃ��f��������������A
	m_model.Init(initData);
	return true;
}
void Game::Update()
{
	
}
void Game::Render(RenderContext& rc)
{
	m_model.Draw(rc);
}