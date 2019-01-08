#pragma once
#include "Scene.h"
#include "GameScene.h"
class MenuScene :public Scene
{
public:
	MenuScene();
	~MenuScene();
	void Init()override;
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
private:
	//float m_fPlateSpawnTimer = 0.f;
	sf::Texture m_texturemenubackground;
	sf::Event ev;
	int v = 100;
	bool is_start = false;
	bool is_click = false;
	bool is_end = false;
	

//	float t = 0;

	//
	Scene *m_sCurrentScene;
	sf::Texture m_Texture_buttonplay;
	sf::Texture m_Texture_buttonskin;
	sf::Texture m_Texture_buttondaily;
	sf::Sprite m_spritebuttonplay;
	sf::Sprite m_spritebuttonskin;
	sf::Sprite m_spritebuttondaily;

	//

};

