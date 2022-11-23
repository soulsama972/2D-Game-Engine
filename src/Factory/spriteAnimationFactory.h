#pragma once
#include"spriteAnimation.h"
#include"baseFactory.h"

#include<string>


/*
this struct contain the necessary information for creating the SpriteAnimation object
*/
struct SpriteAnimationArgs
{
    /*
    \param path path to the image
    \param rowCount the number of images in the row
    \param columnCount the number of images in the column
    \param switchTime the time that each img will be displayed before moving to the next one
    \param removeEmptyInfo remove empty rows/columns that contain only alpha channel will this operation is slow
    the deafult value set to false
    */
    SpriteAnimationArgs(std::string path, int rowCount, int columnCount, float switchTime, bool removeEmptyInfo)
    :path(path), rowCount(rowCount), columnCount(columnCount),switchTime(switchTime),removeEmptyInfo(removeEmptyInfo)
    {}

    std::string path;
    int rowCount;
    int columnCount;
    float switchTime;
    bool removeEmptyInfo;
};

class SpriteAnimationFcatory: public BaseFactory<SpriteAnimation, SpriteAnimationArgs>
{
public:
     ~SpriteAnimationFcatory();

private:
    SpriteAnimation* genreateObject(SpriteAnimationArgs args) override;
};