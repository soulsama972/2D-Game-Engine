#include "entity.h"


sf::RenderWindow* Entity::window = 0;


void Entity::update(float dt)
{

}

void Entity::draw() const
{

}

void Entity::unBindRenderWindow()
{
    window = 0;
}

void Entity::bindRenderWindow(const sf::RenderWindow* _window)
{
    window = (sf::RenderWindow*)(_window);
}