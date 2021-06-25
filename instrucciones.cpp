#include "instrucciones.h"
instrucciones::instrucciones(){
	tfondo.loadFromFile("Assets/Image/floor.jpg");
	sfondo.setTexture(tfondo);
	sfondo.setScale(0.800,0.600);
	tpaper.loadFromFile("Assets/Image/paper2.png");
	spaper.setTexture(tpaper);
	spaper.setPosition(0,-150);
	tguy.loadFromFile("Assets/Image/guy.png");
	sguy.setTexture(tguy);
	sguy.setPosition(200,250);
	tenemi.loadFromFile("Assets/Image/enemy.png");
	senemi.setTexture(tenemi);
	senemi.setScale(0.9,0.9);
	senemi.setPosition(420,240);
	thongo.loadFromFile("Assets/Image/Mushroom.png");
	shongo.setTexture(thongo);
	shongo.setScale(0.1,0.1);
	shongo.setPosition(580,250);
	tfood.loadFromFile("Assets/Image/Food.png");
	sfood.setTextureRect(IntRect(1*(384/24),1*(66/4),384/24,66/4));
	sfood.setTexture(tfood);
	sfood.setPosition(300,240);
	sfood.setScale(3,3);
	
	tcontrol.loadFromFile("Assets/Image/control.png");
	scontrol.setTexture(tcontrol);
	scontrol.setScale(0.1,0.1);
	scontrol.setPosition(190,210);
	ft.loadFromFile("Assets/Font/MetalSlug.ttf");
	b.setFont(ft);
	b.setColor(Color::Green);
	b.setString("Bueno");
	b.setPosition(200,160);
	m.setFont(ft);
	m.setColor(Color::Red);
	m.setString("Malo");
	m.setPosition(450,160);
	twords.setFont(ft);
	twords.setColor(Color::Black);
	twords.setString("Backspace - Volver al Menu");
	twords.setCharacterSize(15);
	twords.setPosition(20,570);
}
void instrucciones::update(float elapsed){
	if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
		Game::getInstance().switchScene(new Menu(),false,0);}
	
}
void instrucciones::draw(RenderWindow &w){
	w.draw(sfondo);
	w.draw(spaper);
	w.draw(sguy);
	w.draw(sfood);
	w.draw(senemi);
	w.draw(scontrol);
	w.draw(shongo);
	w.draw(b);
	w.draw(m);
	w.draw(twords);
}
