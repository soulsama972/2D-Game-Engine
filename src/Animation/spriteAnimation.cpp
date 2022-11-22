#include"spriteAnimation.h"


SpriteAnimation::SpriteAnimation(sf::Sprite* sprite, int rowCount, int columnCount, float switchTime):sprite(sprite)
{
    if(sprite == nullptr)
        throw std::runtime_error("sprite was nullptr");
    
    sf::Vector2u size = sprite->getTexture()->getSize();
    init(rowCount, columnCount, size.x / rowCount, size.y / columnCount, switchTime);
    sprite->setTextureRect({rect.x, rect.y, rect.width, rect.height});
}

void SpriteAnimation::update(float dt, bool flip)
{
    BaseAnimation::update(dt);
    if(flip)
        sprite->setTextureRect({rect.width + rect.x, rect.y, -rect.width, rect.height});
    else
        sprite->setTextureRect({rect.x, rect.y, rect.width, rect.height});
    

}