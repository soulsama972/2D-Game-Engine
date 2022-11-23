#include"spriteAnimationsManager.h"


SpriteAnimationsManager::~SpriteAnimationsManager()
{
    mAnimations.clear();
}



SpriteAnimationsManager::SpriteAnimationsManager(std::vector<SpriteAnimationInfo> spriteAnimtionInfo, std::string currentAnimtionName, bool removeEmptyInfo):
lockTime(0.0f),currentAnimation(nullptr)
{
    
    for(auto& info : spriteAnimtionInfo)
    {
        SpriteAnimationArgs args = SpriteAnimationArgs(info.path, info.rowCount, info.coulmnCount, info.switchTime, removeEmptyInfo);
        SpriteAnimation* spriateAnimation =  spriteAnimationFcatory.safeGenreateObject(args);

        if(spriateAnimation)
        {
            if(info.animtionName.empty())
                info.animtionName = std::filesystem::path(info.path).stem().string();

            mAnimations[info.animtionName] = spriateAnimation;

            if(info.animtionName == currentAnimtionName)
                currentAnimation = spriateAnimation;
        }
    }
}



void SpriteAnimationsManager::update(float dt)
{
    currentAnimation->update(dt);
    
    lockTime -= dt;
}


bool SpriteAnimationsManager::setAnimation(std::string animationName, float lockingTime)
{
    if(lockTime > 0 || mAnimations.find(animationName) == mAnimations.end())
        return false;

    lockTime = lockingTime;

    currentAnimation = mAnimations[animationName];

    return true;
}


void SpriteAnimationsManager::draw(sf::RenderWindow& window,const sf::Vector2f& pos, bool flipImg)
{
    currentAnimation->draw(window, pos, flipImg);
}

void SpriteAnimationsManager::resizeAllSprites(sf::Vector2f size)
{
    for(auto &m : mAnimations)
    {
        sf::Sprite* sprite = m.second->getSprite();
        Rect rect = m.second->getRect();
        sprite->setScale(size.x / rect.width , size.y / rect.height);
    } 

}