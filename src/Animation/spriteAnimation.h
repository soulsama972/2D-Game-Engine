#pragma once
#include"baseAnimation.h"
#include<SFML/Graphics.hpp>


class SpriteAnimation : public BaseAnimation
{
public:
    SpriteAnimation(sf::Sprite* sprite, int rowCount, int columnCount, float switchTime, bool removeEmptyInfo);

    /*
    \param dt delta time
    */
    void update(float dt);


    /*
    \param window the sfml window
    \param pos the position on the screen to display
    */
    void draw(sf::RenderWindow& window,const sf::Vector2f& pos, bool flipImg = false);
    inline sf::Sprite* getSprite() const
    {
        return sprite;
    }

private:
    sf::Sprite* sprite;

};


