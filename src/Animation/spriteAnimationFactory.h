#pragma once
#include"spriteAnimation.h"
#include"../Factory/baseFactory.h"


struct SpriteAnimationArgs
{
    SpriteAnimationArgs(sf::Texture* tex, int rowCount, int columnCount, float switchTime)
    :tex(tex), rowCount(rowCount), columnCount(columnCount),switchTime(switchTime)
    {}

    sf::Texture* tex;
    int rowCount;
    int columnCount;
    float switchTime;
};

class SpriteAnimationFcatory: public BaseFactory<SpriteAnimation, SpriteAnimationArgs>
{
public:


private:
    SpriteAnimation* genreateObject(SpriteAnimationArgs args) override;
};