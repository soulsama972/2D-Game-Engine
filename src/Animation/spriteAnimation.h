#pragma once
#include"baseAnimation.h"
#include<SFML/Graphics.hpp>


class SpriteAnimation : public BaseAnimation
{
public:
    SpriteAnimation(sf::Sprite* sprite, int rowCount, int columnCount, float switchTime);

    /*
    \param dt delta time
    \param flip flip the image horiznotal

    */
    void update(float dt,  bool flip);

    inline sf::Sprite* getSprite() const
    {
        return sprite;
    }

private:
    sf::Sprite* sprite;

};


