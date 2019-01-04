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
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
private:
	int m_isScore;
	float m_speed;
	int m_number = 0;
	float m_mc_x = MC_X;
	mc* player = new mc();
	std::vector<Plate> m_vPlate;
	float m_fPlateSpawnTimer = 0.f;
	Plate* pt;
	sf::Texture m_texturePlate ;
	sf::Texture m_texturePlate_2;
	sf::Texture m_teturecol_g1;
	sf::Texture m_teturecol_1;
	sf::Sprite m_spirtePlate;
	sf::Event ev;
	bool is_jump_up= false;
	bool is_jump_down = false;
	int v = 100;
	int v2 = 100;
	int dir = -1;
	bool is_start = false;
	bool is_click = false;
	float t = 0;
	std::vector<State_Columm> m_vState;
	State_Columm en_st = COLUMMLEVEL_0;
	float change_st = 0;
	bool is_down = false;

};

