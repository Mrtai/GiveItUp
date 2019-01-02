#pragma once
#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 
#include <iostream>

#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;
#define WINDOWS_W	900
#define WINDOWS_H	600
#define FPS_LIMIT	200

#define SPEED	370
#define TEXTURE_MC	"../resources/texture/MC.png"
#define TEXTURE_COLUMM	"../resources/texture/dia.png"
#define TEXTURE_BACKGROUND	"../resources/texture/bk1.jpg"

enum State
{
	LOGO,
	LOADING,
	MENU,
	GAMEPLAY,
	GAMEOVER
};
enum E
{
	MOUSE_LEFT,
	SPACE,
	NO
};

