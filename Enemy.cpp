#include "Enemy.h"

Enemy::Enemy(int num){
	textenemy.loadFromFile("Assets/Image/FatEnemy.png");
	spritenmy.setTexture(textenemy);
		switch(num){
		case 1:
			change(1,Vector2i(0,0),5,Vector2f(20+rand()%680,-90),Vector2f(0,3+rand()%4));
			break;
		case 2:
			change(1,Vector2i(0,1),5,Vector2f(-80,(20+rand()%500)),Vector2f((3+rand()%4),0));
			break;
		case 3:
			change(1,Vector2i(6,0),11,Vector2f(20+rand()%680,620),Vector2f(0,-(3+rand()%4)));
			break;
		case 4:
			change(-1,Vector2i(1,1),4,Vector2f(820,20+rand()%500),Vector2f(-(3+rand()%4),0));
			break;
		default:cout<<"error"<<endl;
		}
	}
void Enemy::update(float elapsed){
	if(x==5){
	spritenmy.move(velenemy);
	timeToMoveEnemy.restart();}
	else if(timeToMoveEnemy.getElapsedTime().asSeconds()>5){
		x++;}
	ppos=spritenmy.getPosition();
	animated();
	if(ppos.x>820||ppos.x<-80||ppos.y>620||ppos.y<-90){
		switch(1+rand()%4){
			case 1:
				change(-1,Vector2i(1,1),4,Vector2f(820,20+rand()%500),Vector2f(-(3+rand()%5),0));
				break;
			case 2:
				change(1,Vector2i(0,1),5,Vector2f(-80,(20+rand()%500)),Vector2f((3+rand()%5),0));
				break;
			case 3:
				change(1,Vector2i(6,0),11,Vector2f(20+rand()%680,620),Vector2f(0,-(3+rand()%5)));
				break;
			case 4:
				change(1,Vector2i(0,0),5,Vector2f(20+rand()%680,-90),Vector2f(0,3+rand()%5));
				break;
				default:cout<<"error"<<endl;}}
	spritenmy.setPosition(ppos);
}
void Enemy::draw(RenderWindow &w){
	w.draw(spritenmy);
}

Sprite &Enemy::getSprite(){
	return spritenmy;
}
void Enemy:: Set_frame(Sprite &sprite_enemey,Vector2i num_frame,int volt,Vector2f size_sp){
	IntRect p(num_frame.x*size_sp.x,num_frame.y*size_sp.y,size_sp.x*(volt),size_sp.y);
	sprite_enemey.setTextureRect(p);
}

void Enemy::animated(){
	if(frame_actual.x<spritelimit){
		frame_actual.x++;
		frame_actual.y=frame_inicial.y;
	}else {frame_actual.x=frame_inicial.x;}
	Set_frame(spritenmy,frame_actual,volt,size_enemy);
}
void Enemy::change(int v,Vector2i fm_inicial,int sp_limit,Vector2f pos,Vector2f vel){
	volt=v;
	frame_inicial=fm_inicial;
	frame_actual=frame_inicial;
	spritelimit=sp_limit;
	ppos=pos;
	velenemy=vel;
	x=rand()%3;
	Set_frame(spritenmy,frame_actual,volt,size_enemy);
	spritenmy.setPosition(ppos);
}
