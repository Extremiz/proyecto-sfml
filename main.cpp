#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"
using namespace sf;

int main(int argc, char *argv[]){
	BaseScene *scene = new Menu();
	Game &g = Game::create(VideoMode(800, 600), scene, "The Game");
	g.run();
	
	return 0;
}
