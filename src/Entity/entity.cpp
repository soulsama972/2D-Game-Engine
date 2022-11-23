#include "entity.h"



Entity::Entity(sf::Vector2f pos, sf::Vector2f size): pos(pos), size(size)
{
    
}

Entity::Entity(SpriteAnimationsManager* animationManager, sf::Vector2f pos, sf::Vector2f size)
: pos(pos), size(size)
{
    setAnimationManager(animationManager);
}


void Entity::setSize(sf::Vector2f size)
{
    this->size = size;
}

void Entity::setSize(float width, float height)
{
    setSize({width, height});
}


void Entity::setAnimationManager(SpriteAnimationsManager* animationManager)
{
    this->animationManager = animationManager;
    this->animationManager->resizeAllSprites(size);
}