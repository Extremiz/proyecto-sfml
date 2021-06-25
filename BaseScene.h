#ifndef BASESCENE_H
#define BASESCENE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
using namespace sf;
using namespace std;
class BaseScene {
public:
	/// constructor
	BaseScene();
	
	/// funci�n que ser� invocada para actualizar la escena
	virtual void update(float elapsed);
	
	/// funci�n que ser� invocada para dibujar la escena
	virtual void draw(RenderWindow &w);
	
	
	/// agrega un nuevo actor a la escena
	void add(Entity *e);
	
	/// eliminar un actor de la escena
	void remove(Entity *e);
	
private:
	vector<Entity *> entities;
	vector<Entity *> to_delete;
};
#endif
