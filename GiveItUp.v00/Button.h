#pragma once
class Button
{

	private:
		sf::Texture m_textureMC;
	public:

		void Init();
		void Update(float dt);
		void Render(RenderWindow &window);
		sf::Sprite m_spriteMC;
		Button();
		Button(int x, int y);
		virtual ~Button();
};
