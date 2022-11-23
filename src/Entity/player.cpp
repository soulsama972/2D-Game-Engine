#include "player.h"



constexpr float speed = 300.0f;
constexpr float MAX_JUMP = 300.0f;


Player::Player(sf::Vector2f pos, sf::Vector2f size):
Entity(pos, size)
{   

}

bool flip = false;
bool Idle = true;
int catStatus = 0;

void Player::update(float dt)
{
    float distance = speed * dt;

    if(keyboard.isKeyPressed(sf::Keyboard::Key::D))
    {
        pos.x += distance;
        if(flip)
            flip = 0;

        Idle = false;
        animationManager->setAnimation("walk", 0);
    }
    
    if(keyboard.isKeyPressed(sf::Keyboard::Key::A))
    {
        pos.x -= distance;
        if(!flip)
            flip = 1;

        Idle = false;
        animationManager->setAnimation("walk", 0);
    }


    if(catStatus == 0 && keyboard.isKeyPressed(sf::Keyboard::Key::W))
        catStatus = 1;


    if(Idle)
        animationManager->setAnimation("idle", 0);

    jump(dt);
    fall(dt);
    fixPos();
    animationManager->update(dt);
     
}

void Player::draw(sf::RenderWindow& window) const
{   
    animationManager->draw(window, {pos.x , window.getView().getSize().y - size.y - pos.y}, flip);
}


void Player::jump(float dt)
{
    if(catStatus == 1)
    {
        if(pos.y > MAX_JUMP) 
        {
            Idle = false;
            catStatus = 2;
            animationManager->setAnimation("hurt", 0.35f);
        }
        
        else
            pos.y += dt * speed; 
    } 
}

void Player::fall(float dt)
{
    float dinstance = dt * speed;

    if(pos.y - dinstance < 0)
    {
        catStatus = 0;
        Idle = true;
    }
    
    if(catStatus == 2) 
        pos.y -= dt * speed; 
  
}

void Player::fixPos()
{
    if(pos.x < 0) pos.x = 0;

    else if(pos.x > 800 - size.x) pos.x = 800 - size.x;

    if(pos.y < 0) pos.y = 0;


}