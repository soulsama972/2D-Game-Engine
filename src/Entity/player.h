#pragma once
#include"entity.h"
#include"Animation/spriteAnimation.h"

#include<vector>
#include<cmath>

constexpr float speed = 300.0f;
constexpr float MAX_JUMP = 300.0f;
class Player : public Entity
{
public:
    Player();
    void update(float dt) override;
    void draw(sf::RenderWindow& window)const override;
    void setAnimations(std::vector<SpriteAnimation*>& animations);

private:
    void jump(float dt);
    void fall(float dt);
    void fixPos();

    sf::Keyboard keyboard;
    sf::Clock clock;
    std::vector<SpriteAnimation*> animations;

    float maxJump;
    int catStatus;
    int currentAmimation;
};
