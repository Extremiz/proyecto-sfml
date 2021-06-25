#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Global.h"
#include "Menu.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "BaseScene.h"
#include "item.h"
#include "GameOver.h"
#include "InputText.h"
using namespace sf;
using namespace std;
class PlayScene: public BaseScene{
private:
	int x=0;
	Music theme;
	item *i;
	vector<item *>items;					///	arreglo con items
	Player *player;							/// el jugador
	Enemy *e;
	vector<Enemy *>enemies;					/// arreglo con enemigos
	Clock timeToEnemy,timeToItem;			/// reloj para medir cuándo crear una nuevo enemigo y item
	int score;								/// puntaje
	Text scoreText,highScoreText,livesText;	/// texto para mostrar el puntaje
	Font fontScoreText;						/// fuente del texto
	Texture texBackground,heart;			/// textura del fondo
	Sprite spBackground,spheart;			/// sprite del fondo
	
public:
	PlayScene();
	void update(float elapsed);
	void draw(RenderWindow &w);
	void createNewItem(int n);          /// agregar nuevo item
	void createNewEnemy(int n);			/// agregar una nuevo enemigo
};
#endif
