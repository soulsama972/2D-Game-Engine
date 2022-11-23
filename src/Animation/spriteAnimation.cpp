#include"spriteAnimation.h"


SpriteAnimation::SpriteAnimation(sf::Sprite* sprite, int rowCount, int columnCount, float switchTime,bool removeEmptyInfo):sprite(sprite)
{
    if(sprite == nullptr) throw std::runtime_error("sprite was nullptr");

    sf::Vector2u size = sprite->getTexture()->getSize();
    if(removeEmptyInfo)
    {
        sf::Image img = sprite->getTexture()->copyToImage();
        unsigned int* buffer = (unsigned int*)img.getPixelsPtr();

        // sf::image call deconstory and remove the buffer do not move this line outside the scope
        init(rowCount, columnCount, size.x, size.y, switchTime, buffer);
    }
    else
        init(rowCount, columnCount, size.x, size.y, switchTime);


    sprite->setTextureRect({rect->x, rect->y, rect->width, rect->height});
}

void SpriteAnimation::update(float dt)
{
    BaseAnimation::update(dt);

}

void SpriteAnimation::draw(sf::RenderWindow& window,const sf::Vector2f& pos, bool flipImg)
{
    if(flipImg)
        sprite->setTextureRect({rect->width + rect->x, rect->y, -rect->width, rect->height});
    else
        sprite->setTextureRect({rect->x, rect->y, rect->width, rect->height});

    sprite->setPosition(pos);
    window.draw(*sprite);
}