#ifndef TOP5_H
#define TOP5_H
#include "BaseScene.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <sstream>
#include "Global.h"
#include <iostream>
#include "PlayScene.h"
#include <fstream>
#include "InputText.h"
#include "controlfile.h"
using namespace sf;
class top5 : public BaseScene {
private:
	Text tmenu;
	Text titleText;
	Text scoreText;
	Text scoreText2;
	Text scoreText3;
	Text scoreText4;
	Text scoreText5;
	Font titleFont;
	int scorefile;
public:
	top5();
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
};
#endif
