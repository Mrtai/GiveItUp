#pragma once
#include "GameObjectRender.h"
class Plate:public GameObjectRender
{
public:
	Plate();
	~Plate();
	Plate(sf::Texture* texture);
	Plate(sf::Texture* texture,float x,float y);
	sf::Sprite m_spritePlate;
};

