#include "player.h"

constexpr float speed = 300.0f;
int frame = 0;
int up = 0;
float oldY;
Player::Player()
{
    tex.loadFromFile("images/Hurt.png");
    sprite.setTexture(tex);
    if(window)
    {
        auto size = window->getSize();
        sprite.setTextureRect({0,0, 48, 48});
        sprite.setPosition(0, size.y - tex.getSize().y - 48);
        sprite.setScale(4, 2);
    }
    clock.restart();
}

void Player::update(float dt)
{
    fVec2 pos = sprite.getPosition();
    if(keyboard.isKeyPressed(sf::Keyboard::Key::D))
        pos.x += speed * dt;
    
    if(keyboard.isKeyPressed(sf::Keyboard::Key::A))
        pos.x -= speed * dt;

    if(!up && keyboard.isKeyPressed(sf::Keyboard::Key::W))
    {
        up = 1;
        oldY = pos.y;
    }

    if(up == 1)
    {
        if(oldY - pos.y > 300)
            up = 2;
        
        else
            pos.y -= speed * dt * 2;
    }
    
    else if(up == 2 && pos.y < window->getSize().y - tex.getSize().y * 2)
    {
        pos.y += speed * dt;
        sprite.setTextureRect({48,0, 48, 48});
    }

    else
    {
        up = 0;
        sprite.setTextureRect({0,0, 48, 48});
    }
        


    sprite.setPosition(pos);
}

void Player::draw() const
{
    if(!window) return;
    window->draw(sprite);
}