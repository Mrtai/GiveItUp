#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}
void GameScene::Init() {

	m_texturePlate.loadFromFile(TEXTURE_COLUMM);
	m_texturePlate_2.loadFromFile(TEXTURE_COLUMM_2);
	float x = 55.f;
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
	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUND))
	{
		cout << "error" << endl;
	}
	else {

		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;
		m_spriteBackground.setTexture(m_textureBackground);
		m_spriteBackground.setScale(ScaleX, ScaleY);
	}
	player->Init();
	pt = new Plate();

}
void GameScene::Render(RenderWindow &window) {
	//Background
	
	window.draw(m_spriteBackground);
	for (size_t i = 0; i < m_vPlate.size(); i++) {
		window.draw(m_vPlate[i].m_spritePlate);
	}
	player->Render(window);
}
void GameScene::Update(float dt, E &e) {
	float dtMultiplier = 64.5f;
	
	if (e == MOUSE_LEFT) {
		//player->Update(dt);
		v = 100;
		v2 = 100;
		is_jump_up = true;
		is_start  = true;
		
	}
	if (e == SPACE) {
		cout << "press space" << endl;
		e = NO;
	}
	
	if (player->m_spriteMC.getPosition().y <= 200) {
		dir = 1;
	}
	if (player->m_spriteMC.getPosition().y >= 320) {
		dir = -1;
	}

	for (size_t i = 0; i < m_vPlate.size(); i++) {
		if (m_vPlate[i].m_spritePlate.getGlobalBounds().intersects(player->m_spriteMC.getGlobalBounds())) {
			if (e == MOUSE_LEFT && m_vState[i + 1] == COLUMMLEVEL_0) {
				cout << m_vState[i+1] << endl;
				is_click = true;
				e = NO;
			}
			m_vPlate[i].m_spritePlate.setTexture(m_texturePlate_2);
		}
		else {
			e = NO;
		}
		
	}
	
	if (is_start) {
		player->m_spriteMC.move(0.f, 150 * dt*dir);
		player->m_spriteMC.setOrigin(144 / 2, 144 / 2);
		player->m_spriteMC.rotate(0.5);
		if (m_fPlateSpawnTimer < 110)
			if (is_click) {
				m_fPlateSpawnTimer += 1.f *4* dt * dtMultiplier;
			}
			else {
				m_fPlateSpawnTimer += 1.f * dt * dtMultiplier;
			}
			
		//Plate spawn
		if (m_fPlateSpawnTimer >= 110)
		{
			cout << m_fPlateSpawnTimer << endl;
			m_vPlate.push_back(Plate(&m_texturePlate));
			m_vState.push_back(COLUMMLEVEL_0);
			m_fPlateSpawnTimer = 0; //reset timer
		}
		//Plate move
		for (size_t i = 0; i < m_vPlate.size(); i++)
		{
			//player->m_spriteMC.setRotation(90);
			if (is_click) {
				/*cout << "vao" << endl;*/
				m_vPlate[i].m_spritePlate.move(-1.f * dt * 4 * dtMultiplier, 0.f);
				t += dt;
				/*cout << t << endl;*/
			}
			else {
				m_vPlate[i].m_spritePlate.move(-1.f * dt * dtMultiplier, 0.f);
			}
			if (t >= 2 )
			{
				is_click = false;
				t = 0;
			}

			//m_vPlate[i].Update(dt);
			if (m_vPlate[i].m_spritePlate.getPosition().x <= 0 - m_vPlate[i].m_spritePlate.getGlobalBounds().width)
			{
				m_vPlate.erase(m_vPlate.begin() + i);
				m_vState.erase(m_vState.begin() + i);
				break;
			}
		}
	}
}

