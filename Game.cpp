#include "Game.h"
Game *Game::instance = nullptr;
Game::Game(){}

Game &Game::create(const VideoMode &videoMode, BaseScene *scene, const string &name){
	if(instance){
		cerr<<"ERROR: can't call create(), game already running."<<endl;
	}else{
		Game & g = getInstance();
		g.window.create(videoMode, name, sf::Style::Close);
		g.nextScene = nullptr;
		g.currentScene = scene;
		g.window.setFramerateLimit(60);
		g.clock.restart();
		
	}
	return getInstance();
	
}


Game &Game::getInstance(){
	if(!instance){
		instance = new Game();
	}
	return *instance;
}

void Game::run(){
	f.loadFromFile("Assets/Font/MetalSlug.ttf");
	text_entrada=new InputText();
	text_entrada->setPosition(120,400);
	text_entrada->setMaxChars(3); // no mas de 10 caracteres
	text_entrada->setSingleWord(true); // no permitir ingresar espacios, para que sea solo una palabra
	text_palabras.setFont(f);
	text_palabras.setCharacterSize(25);
	text_palabras.setColor(sf::Color::Red);
	text_palabras.setPosition(100,100);
	window.setFramerateLimit(60);
	while(window.isOpen() && currentScene != nullptr) {
		Event e;
		while(window.pollEvent(e)){
			if(e.type == Event::Closed){
				window.close();
			}if(needtext){if (e.type==sf::Event::KeyPressed && e.key.code==sf::Keyboard::Return) { // si apretó enter, se toma la palabra y se la agrega a la lista
				string string_ingresado = text_entrada->getValue(); // obtener la palabra que se ingresó
				/*palabras += "\n\t";*/ palabras += string_ingresado;
				text_palabras.setString(palabras);
				controlfile().editlist(palabras,x);
				text_entrada->reset(); // reiniciar la entrada para tomar otra palabra
				needtext=false;
			} else text_entrada->processEvent(e);} // para que el texto tome las teclas que pulsamos
		}text_entrada->update();
		update();
		draw();
		if(nextScene != nullptr){
			delete currentScene;
			currentScene = nextScene;
			nextScene = nullptr;
		}
	}
}
void Game::update(){
	
	currentScene->update(clock.getElapsedTime().asSeconds());
	clock.restart();
}


void Game::draw(){
	
	window.clear(Color::Black);
	if(needtext){
		window.draw(*text_entrada);}
	currentScene->draw(window);
	
	window.display();
}

void Game::switchScene(BaseScene *scene,bool text,int p){
	x=p;
	nextScene = scene;
	needtext=text;
}
void Game::closed(){
	window.close();
}
