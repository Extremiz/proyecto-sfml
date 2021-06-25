#include "item.h"
using namespace std;
item::item(int num){
	it1.loadFromFile("Assets/Image/Food.png");
	it2.loadFromFile("Assets/Image/Mushroom.png");
	state=rand()%2;//booleando para saber si el item es bueno o malo
	switch(num){
	case 1:
		change(Vector2f(820,rand()%540),Vector2f(-8,0),state);
		break;
	case 2:
		change(Vector2f(-80,rand()%540),Vector2f(8,0),state);
		break;
	case 3:
		change(Vector2f(rand()%740,620),Vector2f(0,-8),state);
		break;
	case 4:
		change(Vector2f(rand()%740,-80),Vector2f(0,8),state);
		break;
	default:cout<<"error"<<endl;
	}
}

void item::update(float elapased){
	if(x==5){
	itfood.move(vel_item);
	timetomoveit.restart();}
	else if(timetomoveit.getElapsedTime().asSeconds()>5){
		x++;}
	pos=itfood.getPosition();
	if(pos.x>820||pos.x<-80||pos.y>620||pos.y<-80){
		switch(1+rand()%4){
	case 1:
		change(Vector2f(820,rand()%540),Vector2f(((-5)+rand()%(-4)),0),rand()%2);
		break;
	case 2:
		change(Vector2f(-80,rand()%540),Vector2f((5+rand()%4),0),rand()%2);
		break;
	case 3:
		change(Vector2f(rand()%740,620),Vector2f(0,((-5)+rand()%(-4))),rand()%2);
		break;
	case 4:
		change(Vector2f(rand()%740,-80),Vector2f(0,(5+rand()%4)),rand()%2);
		break;
	default:cout<<"error"<<endl;
		}
	}
	itfood.setPosition(pos);
}
void item::draw(RenderWindow &w){
	w.draw(itfood);
}
void item::change(Vector2f spos,Vector2f vel,int st){
	x=rand()%3;
    vel_item=vel;
	state=st;
	pos=spos;
	itfood.setPosition(pos);
	if(!state){
		itfood.setTextureRect(IntRect(1*(384/24),1*(66/4),384/24,66/4));
		itfood.setTexture(it1);
		itfood.setScale(3,3);
	}else{
		itfood.setTexture(it2);
		itfood.setTextureRect(IntRect(0,0,271 ,261));
		itfood.setScale(0.1,0.1);
	}
}
bool item::isbad(){
	return state;
}
Sprite &item::getSprite(){
	return itfood;
}
