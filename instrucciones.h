#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H
#include "BaseScene.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;
class instrucciones:public BaseScene{
private:
	Texture  tfondo,tpaper,tguy,tenemi,thongo,tfood,tcontrol;
		Sprite sfondo,spaper,sguy,senemi,shongo,sfood,scontrol;
		Text b,m,twords;
		Font ft;
public:
	instrucciones();
	void update(float elapsed);
	void draw(RenderWindow &w);
};
#endif
