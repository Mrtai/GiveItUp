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
	m_spritePlate.setPosition(WINDOWS_W, 350);
	m_spritePlate.setScale(0.5f, 0.5f);
}
