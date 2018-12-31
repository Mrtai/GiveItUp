#pragma once
#include "Scene.h"
#include "mc.h"
#include "Plate.h"
class GameScene:public Scene
{
public:
	GameScene();
	~GameScene();
	void Init()override;
	void Update(float dt) override;
	void Render(RenderWindow &window)override;
private:
	int m_isScore;
	float m_speed;
	mc* player = new mc();
	std::vector<Plate> m_vPlate;
	float m_fPlateSpawnTimer = 0.f;
	Plate* pt;
	sf::Texture m_texturePlate ;
};

