#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "BaseScene.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include <sstream>
#include "Global.h"
#include <iostream>
#include "PlayScene.h"
#include <fstream>
#include "InputText.h"
using namespace sf;
class GameOver : public BaseScene {
private:
	Text name;
	Text info;
	Text enter;
	Text textexit;
	Text textmenu;
	Music theme;
	Text titleText;
	Text scoreText;
	Text pressStartText;
	Font titleFont;
	int scorefile;
	bool x=false;
public:
	GameOver();
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
};
#endif
