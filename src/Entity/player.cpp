#include "player.h"



Player::Player()
{   
    width = 400;
    height = 400;
    xPos = 0;
    yPos = 0;
    catStatus = 0;
    currentAmimation = 0;
    maxJump = MAX_JUMP;

    clock.restart();
}

bool flip = false;
bool idel = false;

void Player::update(float dt)
{

    float distance = speed * dt;
    currentAmimation = 0;
    bool oldIdel = idel;

    if(keyboard.isKeyPressed(sf::Keyboard::Key::D))
    {
        currentAmimation = 1;
        xPos += distance;
        if(flip)
            flip = 0;

        idel = true;
    }
    
    if(keyboard.isKeyPressed(sf::Keyboard::Key::A))
    {
        xPos -= distance;
        currentAmimation = 1;
        if(!flip)
            flip = 1;

        idel = true;
    }

    if(keyboard.isKeyPressed(sf::Keyboard::Key::W))
    {
        catStatus = 1;
        idel = true;
    }

    if(idel != oldIdel)
        animations[currentAmimation]->resertAmimation();

    jump(dt);
    fall(dt);
    fixPos();
    animations[currentAmimation]->update(dt, flip);
     
}

void Player::draw(sf::RenderWindow& window) const
{
    sf::Sprite* sprite = animations[currentAmimation]->getSprite();
    Rect rect = animations[currentAmimation]->getRect();
    
    if(flip)
        rect.width += width / 4;

    sprite->setPosition({xPos - rect.width, window.getView().getSize().y - height + yPos});
    window.draw(*sprite);


}

void Player::setAnimations(std::vector<SpriteAnimation*>& animations)
{
    this->animations = animations;

    for(auto& ani : animations)
    {
        sf::Sprite* sprite = ani->getSprite();
        sf::IntRect rect = sprite->getTextureRect();
        sprite->setScale(width / rect.width, height / rect.height);
    }

}

void Player::jump(float dt)
{
    if(catStatus == 1)
    {
        if(-yPos > MAX_JUMP) 
        {
            catStatus = 2;
            currentAmimation = 2;
            
        }
        
        else
            yPos -= dt * speed; 
    } 
}

void Player::fall(float dt)
{
    float dinstance = dt * speed;

    if(yPos + dinstance > 0)
        catStatus = 0;
    
    if(catStatus == 2) 
        yPos += dinstance; 
  
}

void Player::fixPos()
{
    if(xPos + width / 2 < 0) xPos = 800;

    else if(xPos > 800) xPos = -width / 2;

    if(yPos < 0) yPos = 0;


}