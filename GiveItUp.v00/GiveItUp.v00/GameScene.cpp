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
	player->Render(window);
	window.draw(pt->m_spritePlate);
	for (size_t i = 0; i < m_vPlate.size(); i++) {
		window.draw(m_vPlate[i].m_spritePlate);
	}
	
}
void GameScene::Update(float dt, E &e) {
	float dtMultiplier = 64.5f;
	if (e == MOUSE_LEFT) {
		//player->Update(dt);
		v = 100;
		v2 = 100;
		is_jump_up = true;
		e = NO;
	}
	if (e == SPACE) {
		cout << "press space" << endl;
		e = NO;
	}

	//Player jump
	//if (is_jump_up) {
	//	player->m_spriteMC.move(0.f, -v*dt);
	//	v -= 1;
	//}
	//if (player->m_spriteMC.getPosition().y <= 274)
	//{
	//	is_jump_up = false;
	//	is_jump_down = true;
	//}
	//if (player->m_spriteMC.getPosition().y >= 300 || v2 <= 0) {
	//	is_jump_down = false;
	//}
	//if (is_jump_down) {
	//	player->m_spriteMC.move(0.f, v2*dt);
	//	v2 = v2 - 1;
	//}
	//
	////cout << player->m_spriteMC.getPosition().y << endl;
	//cout << v2 << endl;
	if (player->m_spriteMC.getPosition().y <= 200) {
		dir = 1;
	}
	if (player->m_spriteMC.getPosition().y >= 300) {
		dir = -1;
	}
	player->m_spriteMC.move(0.f, 150 * dt*dir);
	if (m_fPlateSpawnTimer < 110)
		m_fPlateSpawnTimer += 1.f * dt * dtMultiplier;

	//Plate spawn
	if (m_fPlateSpawnTimer >= 110)
	{
		m_vPlate.push_back(Plate(&m_texturePlate));
		m_fPlateSpawnTimer = 0; //reset timer
	}
	//Plate move
	for (size_t i = 0; i < m_vPlate.size(); i++)
	{
		m_vPlate[i].m_spritePlate.move(-1.f * dt * dtMultiplier, 0.f);

		//m_vPlate[i].Update(dt);
		if (m_vPlate[i].m_spritePlate.getPosition().x <= 0 - m_vPlate[i].m_spritePlate.getGlobalBounds().width)
		{
			m_vPlate.erase(m_vPlate.begin() + i);
			break;
		}
	}

}

