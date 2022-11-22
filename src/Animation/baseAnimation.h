#pragma once

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
    \param switchTime how many sec to show before changing to next img
    */
    void init(int rowCont, int columnCount, int width, int height, float switchTime);
    
    /*
        set the timer back to zero
    */
    void resertAmimation();


    Rect getRect() const;
protected:
    /*
    \brief call this function inside your update function
    */
    void update(float dt);
    
    /*
        contain the view part of the current img to show
    */
    Rect rect;

private:
    int rowCount, columnCount;
    float elapsedTime, switchTime;
};


