#pragma once

#include<SFML/Graphics.hpp>

using fVec2 = sf::Vector2<float>;

class Entity
{

public:
    virtual void update(float dt);
    virtual void draw(sf::RenderWindow& window) const;

protected:
    float xPos, yPos, width, height;

private:

};

