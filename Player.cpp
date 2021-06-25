#include "Player.h"
#include <SFML/Graphics/Rect.hpp>
Player::Player(const sf::Vector2f &pos){
	arch.loadFromFile("Assets/Sound/death.ogg");
	arch2.loadFromFile("Assets/Sound/hit.ogg");
	hit.setBuffer(arch2);
	scream.setBuffer(arch);
	hit.setVolume(100);
	scream.setVolume(15);
	timeToparalize.restart();
	textpj.loadFromFile("Assets/Image/FatGuy.png");
	textfat.loadFromFile("Assets/Image/FatGuy2.png");
	spritpj.setTexture(textpj);
	spritpj.setPosition(pos);
	size_actual=small;
	frame_inicial={0,0};
	frame_actual=frame_inicial;
	Set_frame(spritpj,frame_actual,1,size_actual);
	
}
//1134/18,129/2 small
//1134/18,130/2 1fat
//1152/18,385/2 2fat
//1152/12,276/3 3fat
void Player::update(float elapsed){
	// mover al personaje
	if(paralice==5){
	if(Keyboard::isKeyPressed(Keyboard::Left)){
		volt=-1;
		if(size_actual==small){
			spritelimit=18;
			frame_inicial={13,1};
		}else if(size_actual==fat1){
			spritelimit=18;
			frame_inicial={13,3};
		}else if(size_actual==fat2){
			spritelimit=18;
			frame_inicial={13,5};
		}else if(size_actual==fat3){
			spritelimit=6;
			frame_inicial={1,2};
		}
		animated();
		spritpj.move(-CHAR_VEL, 0);
		if(Keyboard::isKeyPressed(Keyboard::Left)&&Keyboard::isKeyPressed(Keyboard::Down)){
			spritpj.move(0, CHAR_VEL);
		}else if(Keyboard::isKeyPressed(Keyboard::Left)&&Keyboard::isKeyPressed(Keyboard::Up)){
			spritpj.move(0, -CHAR_VEL);}
	}else if(Keyboard::isKeyPressed(Keyboard::Right)){
		volt=1;
		if(size_actual==small){
			spritelimit=17;
			frame_inicial={12,1};
		}else if(size_actual==fat1){
			spritelimit=17;
			frame_inicial={12,3};
		}else if(size_actual==fat2){
			spritelimit=17;
			frame_inicial={12,5};
		}else if(size_actual==fat3){
			spritelimit=5;
			frame_inicial={0,2};
		}animated();
		spritpj.move(CHAR_VEL, 0);
		if(Keyboard::isKeyPressed(Keyboard::Right)&&Keyboard::isKeyPressed(Keyboard::Down)){
			spritpj.move(0, CHAR_VEL);
		}else if(Keyboard::isKeyPressed(Keyboard::Right)&&Keyboard::isKeyPressed(Keyboard::Up)){
			spritpj.move(0, -CHAR_VEL);}
	}
	else if(sf::Keyboard::isKeyPressed(Keyboard::Up)){
		volt=1;
		if(size_actual==small){
			spritelimit=11;
			frame_inicial={6,1};
		}else if(size_actual==fat1){
			spritelimit=11;
			frame_inicial={6,3};
		}else if(size_actual==fat2){
			spritelimit=11;
			frame_inicial={6,5};
		}else if(size_actual==fat3){
			spritelimit=11;
			frame_inicial={6,1};
		}animated();
		spritpj.move(0,-CHAR_VEL);
	}
	else if(Keyboard::isKeyPressed(Keyboard::Down)){
		volt=1;
		if(size_actual==small){
			spritelimit=5;
			frame_inicial={0,1};
		}else if(size_actual==fat1){
			spritelimit=5;
			frame_inicial={0,3};
		}else if(size_actual==fat2){
			spritelimit=5;
			frame_inicial={0,5};
		}else if(size_actual==fat3){
			spritelimit=5;
			frame_inicial={0,1};}animated();
	spritpj.move(0,CHAR_VEL);}
	timeToparalize.restart();
	//empujar al chocar
	}else	if(timeToparalize.getElapsedTime().asMilliseconds()<90){spritpj.move(20,20);hit.play();} if(timeToparalize.getElapsedTime().asSeconds()>2){
		paralice++;
	}
	// limitar el movimiento del personaje a la ventana
	Vector2f charPos = spritpj.getPosition();
	if(charPos.x < 5) charPos.x = 5;
	if(charPos.x > 740) charPos.x = 740;
	if(charPos.y < 5) charPos.y = 5;
	if(charPos.y > 520) charPos.y = 520;
	spritpj.setPosition(charPos);
//	cout<<timeToparalize.getElapsedTime().asSeconds()<<endl;
}

void Player::draw(sf::RenderWindow &w){
	w.draw(spritpj);
}

sf::Sprite &Player::getSprite(){
	return spritpj;
}

bool Player::collidesWithEnemy(Enemy *b){
	FloatRect PRect = spritpj.getGlobalBounds();
	FloatRect ERect = b->getSprite().getGlobalBounds();
	return PRect.intersects(ERect);
}
bool Player::collidesWithitem(item *b){
	FloatRect PRect = getSprite().getGlobalBounds();
	FloatRect IRect = b->getSprite().getGlobalBounds();
	return PRect.intersects(IRect);
}
void Player::oneup(int i){
if(i>x){
live+=1;
x=i+x;}
}
void Player::paralize(){
	paralice=0;
}
int Player::getlives(){
	return live;
}
void Player::lostlive(){
	scream.play();
	live=live-1;
	spritpj.setPosition(Vector2f(400, 300));
	paralice=5;
	
}
void Player::Set_frame(Sprite &spritepj,Vector2i num_frame,int volt,Vector2f sizesp){
	IntRect pj(num_frame.x*sizesp.x,num_frame.y*sizesp.y,sizesp.x*volt,sizesp.y);
	spritpj.setTextureRect(pj);
}

void Player::animated(){
	if(frame_actual.x<spritelimit){frame_actual.x++;
	frame_actual.y=frame_inicial.y ;}
	else {frame_actual.x=frame_inicial.x;}
	Set_frame(spritpj,frame_actual,volt,size_actual);
}
bool Player::change(int s){
	if(s==500){
		spritpj.setTexture(textpj);
		size_actual=fat1;
		frame_actual={0,2};
		CHAR_VEL=4.5;
		return true;
	}else if(s==1500){
		spritpj.setTexture(textpj);
		size_actual=fat1;
		frame_actual={0,2};
		CHAR_VEL=CHAR_VEL-1;
		CHAR_VEL=4.1;
		return true;
	}else if(s==2000){
		spritpj.setTexture(textpj);
		size_actual=fat2;
	frame_actual={0,4};
	CHAR_VEL=4;
	return true;
	}else if(s==5000){
		spritpj.setTexture(textfat);
		size_actual=fat3;
		frame_actual={1,1};
		CHAR_VEL=3.5;
		return true;
	}
	else{return false;}
}
