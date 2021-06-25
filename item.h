#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>
using namespace sf;
class item: public Entity{
public:
	item(int num);
	void update(float elapsed) override;
	void draw(RenderWindow &w) override;
	RectangleShape get_item();
	void change(Vector2f spos,Vector2f vel,int st);
	bool isbad();
	Sprite &getSprite();
private:
	int x=5;
	Clock timetomoveit;
	Texture it1,it2;
	Sprite itfood;
Vector2f vel_item;
Vector2f pos;
bool state;
};
#endif
