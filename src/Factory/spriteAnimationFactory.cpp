#include"spriteAnimationFactory.h"




SpriteAnimationFcatory::~SpriteAnimationFcatory()
{
    for(auto& object: getObjects())
    {
        sf::Sprite* sprite = object->getSprite();
        const sf::Texture* tex = sprite->getTexture();
        delete tex;
        delete sprite;
    }
    destoryAllGenreateObject();
}


SpriteAnimation* SpriteAnimationFcatory::genreateObject(SpriteAnimationArgs args)
{
    sf::Texture* tex =  new sf::Texture();
    tex->loadFromFile(args.path);
    if(!tex) return nullptr;

    sf::Sprite* sprite = new sf::Sprite();
    if(!sprite) return nullptr;
    sprite->setTexture(*tex);
    return new SpriteAnimation(sprite, args.rowCount, args.columnCount, args.switchTime, args.removeEmptyInfo);

}