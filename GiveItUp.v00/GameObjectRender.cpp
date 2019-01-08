#include "stdafx.h"
#include "GameObjectRender.h"
float t = 0;
int dir = 1;
void GameObjectRender::Init(const char* textureName, int x, int y){
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
	sprite.setPosition((float)x, (float)y);
	m_vecTextureSize = texture.getSize();
	m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
	//cout << "scale x = " << ScaleX << " scaley = " << ScaleY << endl;
	sprite.setScale(0.5, 0.5);
}
void GameObjectRender::Render(RenderWindow &window) {
	window.draw(sprite);
}
void GameObjectRender::Update(float dt) {
}