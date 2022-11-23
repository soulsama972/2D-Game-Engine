#pragma once
#include "spriteAnimation.h"
#include "spriteAnimationFactory.h"

#include <filesystem>
#include<unordered_map>
#include<string>
#include<vector>


struct SpriteAnimationInfo
{
    /*
    \param path path to the image
    \param animtionName the name of the animation (if no name was pass the name will be the base name of the pathToImage)
    \param rowCount the number of images in the row
    \param columnCount the number of images in the column
    \param switchTime the time that each img will be displayed before moving to the next one
    */    
    SpriteAnimationInfo(std::string path, std::string animtionName, int rowCount, int columnCount, float switchTime)
    {
        this->path = path;
        this->animtionName = animtionName;
        this->rowCount = rowCount;
        this->coulmnCount = columnCount;
        this->switchTime = switchTime;
    }

    std::string path;
    std::string animtionName;
    int rowCount;
    int coulmnCount;
    float switchTime;
};



class SpriteAnimationsManager
{

public:
    ~SpriteAnimationsManager();

    /*
    \param spriteAnimtionInfo a vector conatins infomation about the sprite animtion
    \param currentAnimtionName which animation to display by default
    \param removeEmptyInfo remove empty rows/columns that contain only alpha channel will this operation is slow the deafult value set to false
    */
    SpriteAnimationsManager(std::vector<SpriteAnimationInfo> spriteAnimtionInfo, std::string currentAnimtionName, bool removeEmptyInfo);


    void resizeAllSprites(sf::Vector2f size);

    void update(float dt);

    /*
    \brief change the current animtion
    \param animationName the animation name.
    \param lockingTime the aomunt of time in which you perventing from setting new animation again.
    \returns return false if locking is present or animation Name was not found otherwise returning true
    */
    bool setAnimation(std::string animationName, float lockingTime = 0.0f);
    

    void draw(sf::RenderWindow& window,const sf::Vector2f& pos, bool flipImg);

private:
    float lockTime;
    SpriteAnimation* currentAnimation;
    std::unordered_map<std::string, SpriteAnimation*> mAnimations;
    SpriteAnimationFcatory spriteAnimationFcatory;

};