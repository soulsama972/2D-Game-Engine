#pragma once

#include<SFML/Graphics.hpp>

using fVec2 = sf::Vector2<float>;

class Entity
{

public:
    virtual void update(float dt);

    virtual void draw() const;

    static void bindRenderWindow(const sf::RenderWindow* window);
    static void unBindRenderWindow();

protected:
    static sf::RenderWindow* window;
private:
    
};

