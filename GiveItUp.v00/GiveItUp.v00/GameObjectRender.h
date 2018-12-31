#pragma once
#include "GameObject.h"
class GameObjectRender:public GameObject
{
public:
	void Init(const char * textureName, int x, int y )override;
	void Render(sf::RenderWindow &window);
	void Update(float dt);
	sf::Sprite GetSprite();
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u m_vecTextureSize;
	sf::Vector2u m_vecWindowSize;
	

};

