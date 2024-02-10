#pragma once
class Game : public IGameObject
{
public:
	
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	Model m_model;					// ���f��
	Vector3 m_position;				// ���W
	Quaternion m_rotation;			// ��]
	Vector3 m_scale = g_vec3One;	// �g�嗦
};

