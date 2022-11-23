#pragma once

#include<vector>

struct Rect
{
    int x,y,width,height;
};

class BaseAnimation
{

public:
    BaseAnimation() = default;


    /*
    \param rowCont the number of image that go along x axes 
    \param columnCount the number of image that go along y axes 
    \param width the width of single img
    \param height the height of single img
    \param switchTime the time that each img will be displayed before moving to the next one
    \param buffer if not nullptr the function will remove all pixel that only have value of alpha channel
    */
    void init(int rowCont, int columnCount, int width, int height, float switchTime, unsigned int* buffer = nullptr);
    
    /*
        set the timer back to zero
    */
    void resertAmimation();


    /*
    \returns view part of the current img to show
    */
    Rect getRect() const;
protected:
    /*
    \brief call this function inside your update function
    */
    void update(float dt);
    
    Rect* rect;
private:
    /*
    \returns return the mininum size without the alpha padding
    */
    Rect getImgCleanSize(const unsigned int* buffer,int startX, int startY, int width, int height);

    std::vector<Rect> rects;    
    float elapsedTime, switchTime;
    int idx;



};


