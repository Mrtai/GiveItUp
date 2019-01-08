#include "stdafx.h"
#include "Scene_Skin.h"
SceneSkin::SceneSkin()
{
}


SceneSkin::~SceneSkin()
{
}
void SceneSkin::Init() {

	float x = 55.f;

	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU))
	{
		cout << "error" << endl;
	}
	else {
		//
		m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU);
		m_Texture_buttonplay.loadFromFile(TEXTURE_BACKGROUNDBTNPlay);
		m_Texture_buttonskin.loadFromFile(TEXTURE_BACKGROUNDBTNSkin);
		m_Texture_buttondaily.loadFromFile(TEXTURE_BACKGROUNDBTNCalendar);
		//
		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;
		m_spriteBackground.setTexture(m_textureBackground);



		sf::Vector2u play = m_Texture_buttonplay.getSize();
		sf::Vector2u play2 = m_Texture_buttonskin.getSize();
		sf::Vector2u play3 = m_Texture_buttondaily.getSize();

		m_spritebuttonplay.setPosition(WINDOWS_W / 18 * 4 - play.x / 2, WINDOWS_H / 6 * 5 - play.y / 2);
		m_spritebuttonskin.setPosition(WINDOWS_W / 18 * 9 - play2.x / 2, WINDOWS_H / 6 * 5 - play2.y / 2);
		m_spritebuttondaily.setPosition(WINDOWS_W / 18 * 14 - play3.x / 2, WINDOWS_H / 6 * 5 - play3.y / 2);


		m_spritebuttonplay.setTexture(m_Texture_buttonplay);
		m_spritebuttonskin.setTexture(m_Texture_buttonskin);
		m_spritebuttondaily.setTexture(m_Texture_buttondaily);
		m_spriteBackground.setScale(ScaleX, ScaleY);
	}

}


void SceneSkin::Render(RenderWindow &window) {
	//Background

	window.draw(m_spriteBackground);
	window.draw(m_spritebuttonplay);
	window.draw(m_spritebuttondaily);
	window.draw(m_spritebuttonskin);
	is_start = true;
	for (int i = 0; i < 9; i++) {
		if (i % 5 == 0 && i != 0) {
			m_vPlate.push_back(Plate(&m_texturePlate_2, x, 205.f));
			m_vState.push_back(COLUMMLEVEL_1);
		}
		else {
			m_vPlate.push_back(Plate(&m_texturePlate, x, 350.f));
			m_vState.push_back(COLUMMLEVEL_0);
		}
		x += 110;
	}


}
void SceneSkin::Update(float dt, E & e) {
	v = 100;
	float dtMultiplier = 64.5f;
	if (e == MOUSE_LEFT) {
		//Update(dt);
		RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Spaceship Game!", Style::Default);
		m_sCurrentScene = new GameScene();
		m_sCurrentScene->Init();
		m_sCurrentScene->Render(window);
		m_sCurrentScene->Update(dt, e);


		if (e == MOUSE_LEFT)
		{
		
		}
	}

	if (is_start) {




	}
	if (is_end) {




	}
}
