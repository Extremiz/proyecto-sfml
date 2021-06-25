#include "top5.h"

top5::top5(){
	if(!titleFont.loadFromFile("Assets/Font/MetalSlug.ttf")){
		cerr<<"ERROR: no se encontro la fuente "<<"MetalSlug.ttf"<<endl;
	}
	titleText.setFont(titleFont);
	titleText.setColor(Color::White);
	titleText.setString("TOP 5");
	titleText.setCharacterSize(50);
	// centra el texto
	titleText.setPosition(Vector2f((800-titleText.getLocalBounds().width)/2.0, 0));
	
	scoreText.setFont(titleFont);
	scoreText.setColor(Color::White);
	stringstream ss;
	ss<<"1."<<controlfile().get_name(0)<<"------ "<<controlfile().get_point(0);
	scoreText.setString(ss.str());
	scoreText.setCharacterSize(40);
	scoreText.setPosition(Vector2f((800-scoreText.getLocalBounds().width)/2.0, 150));
	scoreText.setFont(titleFont);
	scoreText.setColor(Color::White);
	stringstream ss2;
	ss2<<"2."<<controlfile().get_name(1)<<"------ "<<controlfile().get_point(1);
	scoreText2.setString(ss2.str());
	scoreText2.setCharacterSize(40);
	scoreText2.setPosition(Vector2f((800-scoreText.getLocalBounds().width)/2.0, 200));
	scoreText2.setFont(titleFont);
	scoreText2.setColor(Color::White);
	stringstream ss3;
	ss3<<"3."<<controlfile().get_name(2)<<"------ "<<controlfile().get_point(2);
	scoreText3.setString(ss3.str());
	scoreText3.setCharacterSize(40);
	scoreText3.setPosition(Vector2f((800-scoreText.getLocalBounds().width)/2.0, 250));
	scoreText3.setFont(titleFont);
	scoreText3.setColor(Color::White);
	stringstream ss4;
	ss4<<"4."<<controlfile().get_name(3)<<"------ "<<controlfile().get_point(3);
	scoreText4.setString(ss4.str());
	scoreText4.setCharacterSize(40);
	scoreText4.setPosition(Vector2f((800-scoreText.getLocalBounds().width)/2.0, 300));
	scoreText4.setFont(titleFont);
	scoreText4.setColor(Color::White); 
	stringstream ss5;
	ss5<<"5."<<controlfile().get_name(4)<<"------ "<<controlfile().get_point(4);
	scoreText5.setString(ss5.str());
	scoreText5.setCharacterSize(40);
	scoreText5.setPosition(Vector2f((800-scoreText.getLocalBounds().width)/2.0, 350));
	scoreText5.setFont(titleFont);
	scoreText5.setColor(Color::White);
	
	tmenu.setFont(titleFont);
	tmenu.setColor(Color::White);
	tmenu.setString("Backspace - Volver al Menu");
	tmenu.setCharacterSize(15);
	tmenu.setPosition(20,560);
}
void top5::update(float elapsed){
	if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
		Game::getInstance().switchScene(new Menu(),false,0);
	}
//	
//	
	
}

void top5::draw(sf::RenderWindow &w){
	BaseScene::draw(w);
	w.draw(titleText);
	w.draw(scoreText);	
	w.draw(scoreText2);
	w.draw(scoreText3);
	w.draw(scoreText4);
	w.draw(scoreText5);
	w.draw(tmenu);
}
