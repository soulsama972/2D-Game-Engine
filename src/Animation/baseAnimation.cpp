#include"baseAnimation.h"



void BaseAnimation::init(int _rowCount, int _columnCount, int width, int height, float _switchTime)
{
    rowCount = _rowCount;
    columnCount = _columnCount;
    switchTime = _switchTime;

    elapsedTime = 0.0f;

    rect = {0, 0, width, height};
}

void BaseAnimation::resertAmimation()
{
    elapsedTime = 0;
}

Rect BaseAnimation::getRect() const
{
    return rect;
}

void BaseAnimation::update(float dt)
{
    elapsedTime += dt;

    if(elapsedTime > switchTime)
    {
        rect.x += rect.width;
        rect.y += rect.height;
        elapsedTime = 0;
    }

    if(rect.x  > rect.width * (rowCount - 1) ) rect.x = 0;

    if(rect.y  > rect.height * (columnCount -1)) rect.y = 0;

}