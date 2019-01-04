#include "stdafx.h"
#include "GameScene.h"

float time_e = 0;
float time_jump = 0;
sf::FloatRect rect_MC;
sf::FloatRect rect_Plate;
GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}
void GameScene::Init() {

	m_texturePlate.loadFromFile(TEXTURE_COLUMM);
	m_texturePlate_2.loadFromFile(TEXTURE_COLUMMG);
	m_teturecol_g1.loadFromFile(TEXTURE_COLUMM_G_1);
	m_teturecol_1.loadFromFile(TEXTURE_COLUMM_1);
	
	float x = 55.f;
	for (int i = 0; i < 9; i++) {
		if (m_number > 4 && m_number <= 8   && m_number != 0) {
			m_vPlate.push_back(Plate(&m_teturecol_1, x, 250.f));
			m_vState.push_back(COLUMMLEVEL_1);
		}
		else {
			m_vPlate.push_back(Plate(&m_texturePlate, x, 350.f));
			m_vState.push_back(COLUMMLEVEL_0);
		}
		x += 110;
		m_number++;
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
	float dtMultiplier = 220.f;

	if (e == MOUSE_LEFT || e == SPACE) {
		//player->Update(dt);
		v = 100;
		v2 = 100;
		is_jump_up = true;
		is_start = true;

	}
	/*if (e == SPACE) {
		cout << "press space" << endl;
		e = NO;
	}*/

	if (player->m_spriteMC.getPosition().y <= 300 + change_st) {
		dir = 1;
	}
	if (player->m_spriteMC.getPosition().y >= 350 + change_st) {
		dir = -1;
	}
	/*if (time_e > 0.02) {
		time_e = 0;
		e = NO;
	}*/
	/*if (is_down) {
		time_jump += dt;
	}
	if (time_jump > 0.05) {
		change_st += 150;
		player->m_spriteMC.move(0.f, change_st);
		is_down = false;
		time_jump = 0;
	}*/
	//for (size_t i = 0; i < m_vPlate.size() - 1; i++) {
	//	if (m_vPlate[i].m_spritePlate.getGlobalBounds().intersects(player->m_spriteMC.getGlobalBounds())) {
	//		//cout << m_vState[i + 1] << endl;
	//		if ((e == MOUSE_LEFT || e  == SPACE) && m_vState[i + 1] == COLUMMLEVEL_0 && m_vState[i] == COLUMMLEVEL_0) {
	//			cout << m_vState[i+1] << endl;
	//				is_click = true;
	//			time_e += dt;
	//		}
	//		else if((e == MOUSE_LEFT || e == SPACE) && m_vState[i+1] == COLUMMLEVEL_1 && en_st - m_vState[i + 1] < 0){
	//			en_st = COLUMMLEVEL_1;
	//			change_st = -150;
	//			//player->m_spriteMC.move(1.f, -change_st);
	//			cout << "------------------------vao" << endl;
	//			time_e += dt;
	//		}
	//		else if (m_vState[i + 1] < en_st && change_st != 0) {
	//			en_st = m_vState[i + 1];
	//			is_down = true;
	//		}
	//		if (m_vState[i] == COLUMMLEVEL_0) {
	//			m_spirtePlate.setTexture(m_texturePlate_2);
	//			m_spirtePlate.setPosition(m_vPlate[i].m_spritePlate.getPosition().x, m_vPlate[i].m_spritePlate.getPosition().y -0.1);
	//			m_vPlate[i].m_spritePlate = m_spirtePlate;
	//		}
	//		else {
	//			m_spirtePlate.setTexture(m_teturecol_g1);
	//			m_spirtePlate.setPosition(m_vPlate[i].m_spritePlate.getPosition().x , m_vPlate[i].m_spritePlate.getPosition().y);
	//			m_vPlate[i].m_spritePlate = m_spirtePlate;
	//		}
	//		
	//		
	//	}
	//	
	//	
	//}
	for (size_t i = 0; i < m_vPlate.size() - 1; i++) {
		rect_MC = player->m_spriteMC.getLocalBounds();
		rect_Plate = m_vPlate[i].m_spritePlate.getGlobalBounds();
		 
		 cout << rect_MC.width << "," << rect_MC.height << endl;
		 cout << rect_Plate.width << "," << rect_Plate.height << endl;
		 if (rect_MC.intersects(rect_Plate)) {
			 if (m_vState[i] == COLUMMLEVEL_1) {

				 sf::Transformable f;
		
				 f.setScale(81, 36);
				 cout << rect_MC.width << "," << rect_MC.height << endl;
				 cout << rect_Plate.width << "," << rect_Plate.height << endl;
				 cout << "==============================================" << endl;

			 }
			 else
			 {
				/* cout << rect_Plate.width << "," << rect_Plate.height << endl;
				 cout << "==============================================" << endl;*/
			 }
		}
		// cout << rect_MC.width << "," << rect_MC.height << endl;
		
			
		

	}

	if (is_start) {
		player->m_spriteMC.move(0.f, 150 * dt*dir);
		/*player->m_spriteMC.setOrigin(144 / 2, 144 / 2);
		player->m_spriteMC.rotate(1);*/
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
			//cout << m_fPlateSpawnTimer << endl;
			if (m_number % 5 == 0 && m_number != 0) {
				m_vPlate.push_back(Plate(&m_teturecol_1,WINDOWS_W , 250.f));
				m_vState.push_back(COLUMMLEVEL_1);
			}
			else {
				m_vPlate.push_back(Plate(&m_texturePlate, WINDOWS_W, 350.f));
				m_vState.push_back(COLUMMLEVEL_0);
			}
			m_number++;
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

