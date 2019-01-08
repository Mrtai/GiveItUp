#include "stdafx.h"
#include "Plate.h"


Plate::Plate()
{
}


Plate::~Plate()
{
}
Plate::Plate(sf::Texture* texture) {
	m_spritePlate.setTexture(*texture);
	m_spritePlate.setPosition(COLUMM_X, COLUMM_Y);
	m_spritePlate.setScale(0.5f, 0.5f);
}
Plate::Plate(sf::Texture* texture, float x, float y) {
	m_spritePlate.setTexture(*texture);
	m_spritePlate.setPosition(x, y);
	m_spritePlate.setScale(0.5f, 0.5f);
}
