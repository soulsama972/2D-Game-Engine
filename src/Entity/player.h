#pragma once
#include"entity.h"



class Player : public Entity
{
public:
    Player();
    void update(float dt) override;
    void draw() const override;
private:
    sf::Texture tex;
    sf::Sprite sprite;
    sf::Keyboard keyboard;
    sf::Clock clock;
};
