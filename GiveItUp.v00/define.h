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
#define MC_X 50
#define MC_Y 300
#define COLUMM_Y 350
#define COLUMM_X 900
#define SPEED	370
#define TEXTURE_MC	"../resources/texture/MC.png"
#define TEXTURE_COLUMM	"../resources/texture/dia.png"
#define TEXTURE_COLUMM_2	"../resources/texture/columm.png"
#define TEXTURE_BACKGROUND	"../resources/texture/bk1.png"
//
#define TEXTURE_BACKGROUNDLOAD "../resources/texture/logo.jpg"
#define TEXTURE_BACKGROUNDMENU "../resources/texture/bkmenu.jpg"
#define TEXTURE_BACKGROUNDBTNPlay "../resources/texture/btnPlay.png"
#define TEXTURE_BACKGROUNDBTNSkin "../resources/texture/btnSkin.png"
#define TEXTURE_BACKGROUNDBTNCalendar "../resources/texture/calendar.jpg"
//
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
enum State_Columm
{
	COLUMMLEVEL_0,
	COLUMMLEVEL_1,
	COLUMMLEVEL_2,
	COLUMMLEVEL_3

};

