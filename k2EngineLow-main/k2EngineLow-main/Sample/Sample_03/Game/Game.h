#pragma once

// �O���錾�B
class Player;
class Background;

class Game : public IGameObject
{
public:
	~Game();
	bool Start() override;
	void Update() override;
private:
	Player* m_player = nullptr;	// �v���C���[
	Background* m_bg = nullptr; // �w�i
};

