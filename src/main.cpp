#include"Entity/player.h"

#include"Animation/spriteAnimationFactory.h"

#include<iostream>

constexpr float VIEW_HEIGHT = 800.0f;
constexpr float VIEW_WIDTH = 800.0f;

void resizeView(sf::RenderWindow& window)
{
    sf::View  view= window.getView();
    float aspectRatio = window.getSize().x / static_cast<float>(window.getSize().y);
    view.setSize(aspectRatio * VIEW_HEIGHT, VIEW_HEIGHT);
    window.setView(view);
}

int main()
{
    sf::Clock clock;
    Player player;
    sf::Texture backgorund,walk,hurt,idle;
    SpriteAnimationFcatory factory;

    backgorund.loadFromFile("images/background.png");
    walk.loadFromFile("images/Walk.png");
    idle.loadFromFile("images/Idle.png");
    hurt.loadFromFile("images/Hurt.png");
    
    std::vector<SpriteAnimation*> animations;
    animations.push_back(factory.safeGenreateObject(SpriteAnimationArgs(&idle, 4,1, 0.4f)));
    animations.push_back(factory.safeGenreateObject(SpriteAnimationArgs(&walk, 6,1, 0.4f)));
    animations.push_back(factory.safeGenreateObject(SpriteAnimationArgs(&hurt, 2,1, 0.4f)));

    sf::Sprite b(backgorund);
    b.setScale(VIEW_WIDTH / 1920, VIEW_HEIGHT / 1080);
    sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "SFML works!");

    window.setVerticalSyncEnabled(true);

    player.setAnimations(animations);

    while (window.isOpen())
    {
        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::Resized)
            resizeView(window);
        }
        window.clear();
        window.draw(b);
        player.update(dt);
        player.draw(window);
        window.display();
    }

    return 0;
}
