#pragma once

#include<vector>

constexpr int NO_LIMIT = -1;

template<typename OBJTYPE,typename ARGS>
class BaseFactory
{
public:
    virtual ~BaseFactory() = default;
    BaseFactory():_limit(NO_LIMIT),objCount(0){}
    /*
    \param limit the amount of genraeted object that can be make.
    */    
    BaseFactory(int limit):_limit(limit),objCount(0){}
    
    /*
    \param limit the amount of genraeted object that can be make.
    */
    void setLimit(int limit);
    
    /*
    \param args sturct contain the arguments that needed for genreate the obj.
    */
    OBJTYPE* safeGenreateObject(ARGS args);

    /*
    remove all object.
    calling the deconstructor of OBJTYPE
    */
    void destoryAllGenreateObject();

protected:
    /*
    when you override the function create sturct that cantain all the
    infomation that you need inorder to genreate your obj
    */
    virtual OBJTYPE* genreateObject(ARGS args) = 0;


private:
    int _limit;
    int objCount;
    std::vector<OBJTYPE*> objs;
};

template<typename OBJTYPE,typename ARGS>
OBJTYPE* BaseFactory<OBJTYPE,ARGS>::safeGenreateObject(ARGS args)
{
    OBJTYPE* obj = nullptr;
    if(_limit == NO_LIMIT || objCount < _limit)
    {
        obj = genreateObject(args);

        if(obj)
        {
            objs.push_back(obj);
            objCount++;
        }
    }
    return obj;
}

template<typename OBJTYPE,typename ARGS>
void BaseFactory<OBJTYPE,ARGS>::setLimit(int limit)
{
    _limit = limit;
}

