#include "Menu.h"
Menu::Menu(){
	Global::highScore=controlfile().max_point();
	if(!titleFont.loadFromFile("Assets/Font/MetalSlug.ttf")){
		cerr<<"ERROR: no se encontro la fuente "<<"MetalSlug.ttf"<<endl;
	}
	titleText.setFont(titleFont);
	titleText.setColor(Color::White);
	titleText.setString("The Big Guy");
	titleText.setCharacterSize(50);
	// centra el texto
	titleText.setPosition(Vector2f((800-titleText.getLocalBounds().width)/2.0,50));
	
	scoreText.setFont(titleFont);
	scoreText.setColor(Color::White);
	stringstream ss;
	ss<<"HIGH SCORE: "<<Global::highScore;
	scoreText.setString(ss.str());
	scoreText.setCharacterSize(40);
	scoreText.setPosition(Vector2f((800-scoreText.getLocalBounds().width)/2.0, 150));
	
	pressStartText.setFont(titleFont);
	pressStartText.setColor(Color::White);
	pressStartText.setString("Presione ENTER para comenzar");
	pressStartText.setCharacterSize(20);
	pressStartText.setPosition(Vector2f((800-pressStartText.getLocalBounds().width)/2.0, 250));
	
	ttop5.setFont(titleFont);
	ttop5.setColor(Color::White);
	ttop5.setString("TAB - Ver TOP5");
	ttop5.setCharacterSize(15);
	ttop5.setPosition(20,560);
	
	texit.setFont(titleFont);
	texit.setColor(Color::White);
	texit.setString("ESC - SALIR");
	texit.setCharacterSize(15);
	texit.setPosition(650,560);
	
	
	info.setFont(titleFont);
	info.setColor(Color::White);
	info.setString("2020 - This Game was Made By Cristian Zini");
	info.setCharacterSize(15);
	info.setPosition(10,0);
	
	ayuda.setFont(titleFont);
	ayuda.setColor(Color::White);
	ayuda.setString("F1-ayuda");
	ayuda.setCharacterSize(15);
	ayuda.setPosition(350,560);
}

void Menu::update(float elapsed){
	if(Keyboard::isKeyPressed(Keyboard::Return)){
		Game::getInstance().switchScene(new PlayScene(),false,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		Game::getInstance().closed();
	}
	if(Keyboard::isKeyPressed(Keyboard::Tab)){
		Game::getInstance().switchScene(new top5(),false,0);
	}
//	if(Keyboard::isKeyPressed(Keyboard::LShift)){
//		Game::getInstance().switchScene(new GameOver(),true,100000);Global::pjscore=100000;}
//	if(Keyboard::isKeyPressed(Keyboard::LAlt)){
//		Game::getInstance().switchScene(new GameOver(),false,0);Global::pjscore=0;}
	if(Keyboard::isKeyPressed(Keyboard::F1)){
		Game::getInstance().switchScene(new instrucciones(),false,0);
	}
}

void Menu::draw(RenderWindow &w){
	BaseScene::draw(w);
	w.draw(titleText);
	w.draw(scoreText);
	w.draw(pressStartText);
	w.draw(ttop5);
	w.draw(texit);
	w.draw(info);
	w.draw(ayuda);
}
