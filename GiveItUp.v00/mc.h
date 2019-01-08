#pragma once
#include "define.h"
class mc
{
private:
	sf::Texture m_textureMC;
public:
	mc();
	~mc();
	void Init();
	void Update(float dt);
	void Render(RenderWindow &window);
	sf::Sprite m_spriteMC;
};

