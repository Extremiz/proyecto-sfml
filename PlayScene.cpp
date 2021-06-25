#include "PlayScene.h"
using namespace std;
PlayScene::PlayScene(){
	srand(time(0));
	theme.openFromFile("Assets/Sound/ThemeScene.ogg");
	theme.setVolume(20);
	theme.setLoop(true);
	theme.play();
	player = new Player(Vector2f(400, 300));
	add(player);
	Enemy *e=new Enemy(1+rand()%4);
	enemies.push_back(e);
	add(e);
	i=new item(1+rand()%4);
	items.push_back(i);
	add(i);	
	if(!fontScoreText.loadFromFile("Assets/Font/MetalSlug.ttf")){
		cerr<<"ERROR: no se encontro la fuente "<<"MetalSlug.ttf"<<endl;
	}
	heart.loadFromFile("Assets/Image/heart.png");
	spheart.setTexture(heart);
	spheart.setPosition(680,565);
	spheart.setScale(0.5,0.5);
	texBackground.loadFromFile("Assets/Image/floor.jpg");
	spBackground.setTexture(texBackground);
	spBackground.setScale(0.800,0.600);
	score = 0;
	scoreText.setFont(fontScoreText);
	scoreText.setColor(Color::Black);
	highScoreText.setFont(fontScoreText);
	highScoreText.setColor(Color::Black);
	highScoreText.setPosition(350,0);
	livesText.setFont(fontScoreText);
	livesText.setColor(Color::Black);
	livesText.setPosition(720,568);
	timeToEnemy.restart();
}
void PlayScene::update(float elapsed){
	BaseScene::update(elapsed);
//	ingresar nuevos enemigos a la partida
	if(x<=4){
		if(timeToEnemy.getElapsedTime().asSeconds()>3){
			createNewEnemy(1+rand()%4);
			timeToEnemy.restart();
			x++;
/*			cout<<"enemigo automatico creado"<<endl;*/
	}}
	if(x<=2){
		if(timeToItem.getElapsedTime().asSeconds()>3){
			createNewItem(1+rand()%4);
			timeToItem.restart();
			x++;
//			cout<<"item automatico creado"<<endl;
		}}
//	colision con items
	for(const auto &item: items){
		if(	player->collidesWithitem(item)){
			if(!item->isbad()){
				switch(1+rand()%4){
				case 1:
					item->change(Vector2f(820,rand()%540),Vector2f(-8,0),rand()%3);
					break;
				case 2:
					item->change(Vector2f(-80,rand()%540),Vector2f(8,0),rand()%3);
					break;
				case 3:
					item->change(Vector2f(rand()%740,620),Vector2f(0,-8),rand()%3);
					break;
				case 4:
					item->change(Vector2f(rand()%740,-80),Vector2f(0,8),rand()%3);
					break;
				default:cout<<"error"<<endl;}
				score+=100;	
				if(player->change(score)){createNewEnemy(1+rand()%4);
				createNewItem(1+rand()%4);/*cout<<"nuevo enemigo"<<endl;cout<<"nuevo item"<<endl;*/}
				player->oneup(score);
				if(score>Global::highScore){
					Global::highScore=score;
					Global::pjscore=score;
				}
			}
			//control y consulta de las vidas
			else if((player->getlives())!=0){
				switch(1+rand()%4){
				case 1:
					item->change(Vector2f(820,rand()%540),Vector2f(-8,0),rand()%3);
					break;
				case 2:
					item->change(Vector2f(-80,rand()%540),Vector2f(8,0),rand()%3);
					break;
				case 3:
					item->change(Vector2f(rand()%740,620),Vector2f(0,-8),rand()%3);
					break;
				case 4:
					item->change(Vector2f(rand()%740,-80),Vector2f(0,8),rand()%3);
					break;
				default:cout<<"error"<<endl;}
				player->lostlive();}
			else{ if(score > Global::highScore){
					Global::highScore = score;
					}
			theme.stop();
			if(controlfile().entreeneltop(score)){
				Game::getInstance().switchScene(new GameOver(),true,score);
				Global::pjscore=score;
			}else{Game::getInstance().switchScene(new GameOver(),false,0);}
			BaseScene::remove(player);
			for(const auto &Enemy: enemies){
				BaseScene::remove(Enemy);
			}
			for(const auto &item: items){
				BaseScene::remove(item);
			}
			
			}
		}
	}
	//colision con enemigos
	for(const auto &Enemy: enemies){
		if(player->collidesWithEnemy(Enemy)){
			player->paralize();
		}
	}
	// actualiza el puntaje y vidas
	stringstream tmp,tmp2,tmp3;
	tmp<<"SCORE: "<<int(score);
	scoreText.setString(tmp.str());
	tmp2<<"HI-SCORE: "<<Global::highScore;
	highScoreText.setString(tmp2.str());
	tmp3<<"X"<<player->getlives();
	livesText.setString(tmp3.str());
}
void PlayScene::draw(RenderWindow &w){
	w.draw(spBackground);
	BaseScene::draw(w);
	w.draw(spheart);
	w.draw(scoreText);
	w.draw(highScoreText);
	w.draw(livesText);
	
}
void PlayScene::createNewEnemy(int n){
	Enemy *e=new Enemy(n);
	enemies.push_back(e);
	add(e);
}
void PlayScene::createNewItem(int n){
	item *e=new item(n);
	items.push_back(e);
	add(e);
}
