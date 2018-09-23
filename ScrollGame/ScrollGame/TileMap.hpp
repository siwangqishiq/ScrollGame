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

struct Tile{
    long id;
    int ishit;
};

struct TileSet{
    int firstgid;
    std::string name;
    int tileWidth;
    int tileHeight;
    std::string imagePath;
    int imageWidth;
    int imageHeight;
    std::vector<Tile> tiles;
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
private:
    int mWidth;
    int mHeight;
};

class TileMap : public ILayer{
public:
    bool loadMap(const std::string file);
    
    virtual void update();
    virtual void render();
    
private:
    std::vector<Layer *> m_layers;
    TileSet mTileSet;
    
    int mMapWidth;
    int mMapHeight;
    int mTileSize;
};

#endif /* TileMap_hpp */
