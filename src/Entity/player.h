#pragma once
#include"entity.h"




class Player : public Entity
{
public:
    Player(sf::Vector2f pos, sf::Vector2f size);
    void update(float dt) override;
    void draw(sf::RenderWindow& window)const override;

private:
    void jump(float dt);
    void fall(float dt);
    void fixPos();

    sf::Keyboard keyboard;

};
