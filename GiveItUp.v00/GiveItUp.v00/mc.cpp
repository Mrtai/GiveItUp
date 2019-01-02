#include "stdafx.h"
#include "mc.h"


mc::mc()
{
}


mc::~mc()
{
}	
void mc::Init() {
	if (!m_textureMC.loadFromFile(TEXTURE_MC))
		cout << "erorr load" << endl;
	else {
		m_spriteMC.setTexture(m_textureMC);
		m_spriteMC.setScale(0.5, 0.5);
		m_spriteMC.setPosition(50, 300);
	}
}
void mc::Update(float dt) {
	
}
void mc::Render(RenderWindow &window){
	window.draw(m_spriteMC);
}

