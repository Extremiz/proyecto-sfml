#include "GameOver.h"
GameOver::GameOver(){
	theme.openFromFile("Assets/Sound/GameOver.ogg");
	theme.setVolume(20);
	theme.play();
	if(!titleFont.loadFromFile("Assets/Font/MetalSlug.ttf")){
		cerr<<"ERROR: no se encontro la fuente "<<"MetalSlug.ttf"<<endl;
	}
	titleText.setFont(titleFont);
	titleText.setColor(Color::White);
	titleText.setString("GAME OVER");
	titleText.setCharacterSize(50);
	// centra el texto
	titleText.setPosition(Vector2f((800-titleText.getLocalBounds().width)/2.0, 50));
	
	scoreText.setFont(titleFont);
	scoreText.setColor(Color::White);
	stringstream ss;
	ss<<"HIGH SCORE: "<<Global::highScore;
	scoreText.setString(ss.str());
	scoreText.setCharacterSize(40);
	scoreText.setPosition(Vector2f((800-scoreText.getLocalBounds().width)/2.0, 150));
	
	pressStartText.setFont(titleFont);
	pressStartText.setColor(Color::White);
	pressStartText.setString("Presione R para Volver a Jugar");
	pressStartText.setCharacterSize(20);
	pressStartText.setPosition(Vector2f((800-pressStartText.getLocalBounds().width)/2.0, 250));
	
	textmenu.setFont(titleFont);
	textmenu.setColor(Color::White);
	textmenu.setString("Backspace - Volver al Menu");
	textmenu.setCharacterSize(15);
	textmenu.setPosition(20,560);
	
	textexit.setFont(titleFont);
	textexit.setColor(Color::White);
	textexit.setString("ESC - SALIR");
	textexit.setCharacterSize(15);
	textexit.setPosition(650,560);
	
	enter.setFont(titleFont);
	enter.setColor(Color::White);
	enter.setString("Presiona Enter");
	enter.setCharacterSize(20);
	enter.setPosition(250, 250);
	
	info.setFont(titleFont);
	info.setColor(Color::White);
	info.setString("2020 - This Game was Made By Cristian Zini");
	info.setCharacterSize(15);
	info.setPosition(10,0);
	
	name.setFont(titleFont);
	name.setColor(Color::White);
	name.setString("Ingresa tu nombre - (Maximo 3 caracteres)");
	name.setCharacterSize(15);
	name.setPosition(100,350);
}

void GameOver::update(float elapsed){
	if(Keyboard::isKeyPressed(Keyboard::Return)){
		x=true;
	}
	if(x){
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		theme.stop();
		Game::getInstance().closed();
	}
	if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
		theme.stop();
		Game::getInstance().switchScene(new Menu(),false,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::R)){
		theme.stop();
		Game::getInstance().switchScene(new PlayScene(),false,0);}		
	}
}

void GameOver::draw(sf::RenderWindow &w){
	BaseScene::draw(w);
	w.draw(titleText);
	w.draw(scoreText);
	w.draw(info);
	
	if(x){
		w.draw(pressStartText);
		w.draw(textmenu);
		w.draw(textexit);
		
	}
	if(!x){
		w.draw(enter);
	if(controlfile().entreeneltop(Global::pjscore)){
		w.draw(name);
		}}
	

}
