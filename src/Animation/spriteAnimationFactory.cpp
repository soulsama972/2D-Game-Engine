#include"spriteAnimationFactory.h"





SpriteAnimation* SpriteAnimationFcatory::genreateObject(SpriteAnimationArgs args)
{

    sf::Sprite* sprite = new sf::Sprite(*args.tex);
   return new SpriteAnimation(sprite, args.rowCount, args.columnCount, args.switchTime);

}