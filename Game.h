#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "BaseScene.h"
#include <iostream>
#include "InputText.h"
#include "controlfile.h"
using namespace sf;
using namespace std;


/***
* Clase para manejar un bucle de juego con distintas escenas
*/
class Game {
public:
	/// comenzar el bucle de juego
	void run();
	
	/// cambiar la escena actual por otra 
	void switchScene(BaseScene *scene,bool text,int p);
	
	/// obtener la instancia de juego (singleton)
	static Game &getInstance();
	
	/// crear un juego especificando el modo de video y la escena inicial
	static Game &create(const VideoMode &videoMode, BaseScene *scene, const string &name = "");
	void closed();
private:	
	controlfile a;
	int x;
	RenderWindow window;
	bool needtext=false;
	BaseScene *currentScene, *nextScene;
	Clock clock;
	InputText *text_entrada;
	Text text_palabras;
	string palabras;
	Font f;
	void processEvents();
	void update();
	void draw();
	static Game *instance;
	Game();
};

#endif
