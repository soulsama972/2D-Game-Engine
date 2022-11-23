#pragma once
#include<SFML/Graphics.hpp>
#include"spriteAnimationsManager.h"


class Entity
{

public:
    Entity(sf::Vector2f pos, sf::Vector2f size);
    Entity(SpriteAnimationsManager* animationManager, sf::Vector2f pos, sf::Vector2f size);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);

    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
    
    void setAnimationManager(SpriteAnimationsManager* animationManager);


protected:
    sf::Vector2f pos, size;
    SpriteAnimationsManager* animationManager;

};

