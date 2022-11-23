#include"Entity/player.h"

#include"Animation/spriteAnimationsManager.h"

#include<iostream>

constexpr float VIEW_HEIGHT = 600.0f;
constexpr float VIEW_WIDTH = 800.0f;

constexpr float PLAYER_SIZE = 300;

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
    Player player({0,0}, {PLAYER_SIZE, PLAYER_SIZE});
    sf::Texture backgorund;
    std::vector<SpriteAnimationInfo> saInfo;
    saInfo.push_back(SpriteAnimationInfo("images/Idle.png", "idle", 4, 1, 0.4f));
    saInfo.push_back(SpriteAnimationInfo("images/Walk.png", "walk", 6, 1, 0.1f));
    saInfo.push_back(SpriteAnimationInfo("images/Hurt.png", "hurt", 2, 1, 0.1f));
    SpriteAnimationsManager spriteAnimationsManager(saInfo, "idle", true);

    backgorund.loadFromFile("images/background.png");

    sf::Sprite b(backgorund);
    b.setScale(VIEW_WIDTH / 1920, VIEW_HEIGHT / 1080);
    sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "TEST!");

    window.setFramerateLimit(120);

    player.setAnimationManager(&spriteAnimationsManager);

    while (window.isOpen())
    {
        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

         //   if(event.type == sf::Event::Resized)
          //  resizeView(window);
        }
        window.clear();
        window.draw(b);
        player.update(dt);
        player.draw(window);
        window.display();
    }

    return 0;
}
