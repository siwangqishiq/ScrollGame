//
//  TileMap.hpp
//  ScrollGame
//
//  Created by panyi  on 2018/9/6.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#ifndef TileMap_hpp
#define TileMap_hpp
#include <vector>
#include <string>
#include <map>
#include "tinyxml.h"

struct Tile{
    int id;
    int ishit;
    int leftOffset = -1;
    int topOffset = -1;
};

struct TileSet{
    int firstgid;
    std::string name;
    int tileWidth;
    int tileHeight;
    int tilecount;
    int columns;
    std::string imagePath;
    int imageWidth;
    int imageHeight;
    std::map<int,Tile> tiles;
};

class ILayer{
public:
    virtual void update() = 0;
    virtual void render() = 0;
};

class Layer : public ILayer{
public:
    virtual void update();
    virtual void render();
    int *data;
    
    Layer(int w,int h):mWidth(w),mHeight(h){
        data = new int[mWidth * mHeight];
    }
    
    ~Layer(){
        delete []data;
    }
    
    void setName(std::string _name){
        this->name = _name;
    }
    
    int getWidth(){
        return this->mWidth;
    }
    
    int getHeight(){
        return this->mHeight;
    }
    
    std::string getName(){
        return this->name;
    }
private:
    int mWidth;
    int mHeight;
    std::string name;
};

class TileMap : public ILayer{
public:
    bool loadMap(const std::string file);
    
    virtual void update();
    virtual void render();
    
    ~TileMap()
    {
        for(Layer *pLay : mLayers)
        {
            delete pLay;
        }
    }
    
private:
    std::vector<Layer *> mLayers;
    TileSet mTileSet;
    
    int mMapWidth;
    int mMapHeight;
    int mTileSize;
    
    bool parseTileset(TiXmlElement *e);
    
    bool parseLevel(TiXmlElement *e);
};

#endif /* TileMap_hpp */
