#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
using namespace sf;
class Entity {
public:
	virtual void update(float elapsed) = 0;
	virtual void draw(RenderWindow &w) = 0;
};

#endif
