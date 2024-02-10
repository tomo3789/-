#pragma once
// �v���C���[�N���X�B
class Player : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc);
private:
	
	Model m_model;					// ���f��
	Vector3 m_position;				// ���W
	Quaternion m_rotation;			// ��]
	CharacterController m_charaCon;	// �L�����R���B
};

