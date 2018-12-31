// GiveItUp.v00.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "define.h"
#include "SceneManager.h"
#include <Windows.h>


int main()
{
	srand((unsigned int)time(NULL));
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Spaceship Game!", Style::Default);
	window.setFramerateLimit(FPS_LIMIT);

	// ============================ Init ============================
	SceneManager::GetInstance()->Init();

	Clock clock;
	Time elapsed;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		elapsed = clock.getElapsedTime();
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		float dt = clock.getElapsedTime().asMicroseconds() * 1.0f / 1000000;
		//std::cout << "dt: " << dt << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		clock.restart();

		// ================================ Update ================================ 
		SceneManager::GetInstance()->Update(dt);

		// ================================ Draw ================================ 
		window.clear();
		SceneManager::GetInstance()->Render(window);

		window.display();

	//==================================================
	//srand(time(NULL));
	//sf::RenderWindow window(sf::VideoMode(WINDOWS_W, WINDOWS_H), "GiveItUp");
	//window.setFramerateLimit(200);
	//SceneManager::GetInstance()->Init();
	//DWORD start, end;
	//DWORD deltatime;
	//start = GetTickCount();
	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}
	//	end = GetTickCount();
	//	deltatime = end - start;
	//	//Update-------------------------------------------------------Update
	//	SceneManager::GetInstance()->Update((float)deltatime / 1000.0f);
	//	//Draw----------------------------------------------------------Draw
	//	window.clear();
	//	SceneManager::GetInstance()->Render(window);
	//	//window.draw(m_spriteBackground);
	//	window.display();
	//	start = end;
	}

	return 0;
}

