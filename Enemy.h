#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
using namespace sf;
class Enemy	: public Entity{
public:
	Enemy(int num);
	void update(float elapsed) override;
	void draw(RenderWindow &w) override;
	Sprite &getSprite();
	void animated();
	void change(int v,Vector2i fm_inicial,int sp_limit,Vector2f pos,Vector2f vel);
	void Set_frame(Sprite &sprite_enemey,Vector2i num_frame,int volt,Vector2f size_sp);
private:
	Clock timeToMoveEnemy;
	int volt,spritelimit;
	Vector2f velenemy,size_enemy={1110/12,275/3};
	Vector2f ppos;
	Vector2i frame_actual,frame_inicial;
	int x=5;
	Sprite spritenmy;
	Texture textenemy;
};
#endif
