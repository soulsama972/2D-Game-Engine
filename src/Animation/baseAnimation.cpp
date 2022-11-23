#include"baseAnimation.h"

void BaseAnimation::init(int rowCount, int columnCount, int width, int height, float _switchTime, unsigned int* buffer)
{
    idx = 0;
    switchTime = _switchTime;
    elapsedTime = 0.0f;

    int xStart = 0, yStart = 0;
    Rect rect = {0};

    /*
        we dont have the buffer so we calcaute the default behavior
    */
    if(!buffer)
    {
        width /= rowCount;
        height /= columnCount;
        rect.width = width;
        rect.height = height;
        
        for(int  col = 0; col < columnCount; col++)
        {
            for(int row = 0; row < rowCount; row++)
            {
                rects.push_back(rect);
                rect.x += rect.width;
            }
            rect.x = 0;
            rect.y += rect.height;
        }
    }

    /*
        since we have the buffer we can try to find the real value of rect
        looping every row and comlumn and save the xStart,yStart, xEnd and yEnd
        and resize the image to the current one
        todo try to optimatize it late
    */
    else
    {
        for(int  col = 0; col < columnCount; col++)
        {
            int maxHeight = 0;
            int maxWidth = 0;
            for(int row = 0; row < rowCount; row++)
            {
                rect = getImgCleanSize((unsigned int *)buffer,xStart, yStart, width, height);
                xStart = rect.width + rect.x;
                maxWidth = std::max(maxWidth, rect.width);
                maxHeight = std::max(maxHeight, rect.height);
                rects.push_back(rect);
            }
            for(auto& r: rects)
            {
                r.height = maxHeight;
                r.width = maxWidth;
            }
            yStart = rect.y + rect.height;
            xStart = 0;
        }
    }


    this->rect = &rects[idx];
}

void BaseAnimation::resertAmimation()
{
    elapsedTime = 0;
}

Rect BaseAnimation::getRect() const
{
    return rects[idx];
}

void BaseAnimation::update(float dt)
{
    elapsedTime += dt;

    if(elapsedTime > switchTime)
    {
        idx++;
        idx %= rects.size();
        rect = &rects[idx];
        elapsedTime = 0;
    }

}

Rect BaseAnimation::getImgCleanSize(const unsigned int* buffer,int xStart, int yStart, int width, int height)
{
    int endX = -1 , endY = -1;
    int defaultY = yStart;
    int defaultX = xStart;
    
    for(int y = defaultY; y < height; y++)
    {
        bool emptyRow = true;
        
        for(int x = defaultX; x < width; x++)
        {
            if(buffer[y * width + x] != 0)
            {
                emptyRow = false;
                if(yStart == defaultY) 
                    yStart = y;

                if(x < xStart  || xStart  == defaultX)
                    xStart = x;

            }
        }

        if(emptyRow && yStart != defaultY && endY == -1)
            endY = y;
 
    }

    for(int x = xStart; x < width; x++)
    {
        bool emptyColumn = true;
    
        for(int y = yStart; y < height; y++)
        {
            if(buffer[y * width + x] != 0)
                emptyColumn = false;
        
        }  

        if(emptyColumn)
        {
            endX = x;
            break;
        }
    }

    if(xStart == defaultX) xStart = 0;
    if(yStart == defaultY) yStart = 0;
    if(endX == -1) endX = width;
    if(endY == -1) endY = height;


    width = endX - xStart;
    height = endY - yStart;

    return {xStart, yStart, width, height};
}