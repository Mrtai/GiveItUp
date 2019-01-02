#pragma once
#include "GameObjectRender.h"
class Plate:public GameObjectRender
{
public:
	Plate();
	~Plate();
	Plate(sf::Texture* texture);
	sf::Sprite m_spritePlate;
};

