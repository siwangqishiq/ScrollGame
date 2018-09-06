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

class ILayer{
public:
    virtual void update() = 0;
    virtual void render() = 0;
};

class Layer : public ILayer{
public:
    virtual void update();
    virtual void render();
};

class TileMap : public ILayer{
public:
    bool loadMap(const std::string file);
    virtual void update();
    virtual void render();
    
private:
    std::vector<Layer *> m_layers;
};

#endif /* TileMap_hpp */
