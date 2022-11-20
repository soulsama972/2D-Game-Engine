#include"Entity/player.h"

#include<iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 800), "SFML works!");
    sf::Clock clock;
    Entity::bindRenderWindow(&window);
    window.setVerticalSyncEnabled(true);
    Player cat;
    while (window.isOpen())
    {
        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        int count = 0;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            count++;
        }
        window.clear();
        cat.update(dt);
        cat.draw();
        window.display();
    }

    return 0;
}
