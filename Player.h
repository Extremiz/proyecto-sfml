#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Enemy.h"
#include "item.h"
#include "Global.h"
using namespace sf;
class Player: public Entity{
public:
	Player(const Vector2f &pos);
	void update(float elapsed) override;
	void draw(RenderWindow &w) override;
	Sprite &getSprite();
	bool collidesWithEnemy(Enemy *b);
	void oneup(int i);
	bool collidesWithitem(item *c);
	void paralize();
	int getlives();
	void lostlive();
	void Set_frame(Sprite &spritepj,Vector2i num_frame,int volt,Vector2f sizesp);
	void animated();
	bool change(int s);
private:
	int volt;
	int x=10000;
	SoundBuffer arch,arch2;
	Sound scream,hit;
	Vector2f small{1134/18,130/2}; 
	Vector2f fat1 {1150/18,257/4};
	Vector2f fat2 {1160/18,385/6};
	Vector2f fat3 {1098/12,275/3};
	Vector2f size_actual;
	Vector2i frame_actual={0,2},frame_inicial;
	Sprite spritpj;
	Texture textpj,textfat;
	Clock timeToparalize,clock;
	float CHAR_VEL = 5;
	int paralice=5;
	int live=3;
	int spritelimit;

};
#endif
	
