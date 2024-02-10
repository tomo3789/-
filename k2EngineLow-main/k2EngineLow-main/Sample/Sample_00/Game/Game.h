#pragma once
class Game : public IGameObject
{
public:
	
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	Model m_model;
};

