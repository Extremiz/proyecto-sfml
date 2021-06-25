#ifndef MENU_H
#define MENU_H
#include "BaseScene.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <sstream>
#include "Global.h"
#include <iostream>
#include "PlayScene.h"
#include "top5.h"
#include "instrucciones.h"
using namespace sf;
class Menu : public BaseScene {
private:
	Text ayuda;
	Text titleText;
	Text scoreText;
	Text pressStartText;
	Font titleFont;
	Text ttop5;
	Text thelp;
	Text texit;
	Text info;
	
public:
	Menu();
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
};
#endif
