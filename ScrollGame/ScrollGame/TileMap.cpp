//
//  TileMap.cpp
//  ScrollGame
//
//  Created by panyi  on 2018/9/6.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#include "TileMap.hpp"
#include "tinyxml.h"

#include <iostream>
using namespace std;

void TileMap::update()
{
    for(Layer *player : m_layers)
    {
        player->update();
    }//end for each
}


void TileMap::render()
{
    for(Layer *player : m_layers)
    {
        player->render();
    }//end for each
}

bool TileMap::loadMap(const std::string file)
{
    if(file == "")
        return false;
    
    TiXmlDocument doc(file.c_str());
    if(!doc.LoadFile()){
        return false;
    }
    
    doc.Print();
    
    TiXmlElement *root = doc.RootElement();
    
    root->Attribute("width", &this->mMapWidth);
    root->Attribute("height" , &this->mMapHeight);
    cout << "map width = " << this->mMapWidth << "  height = " << this->mMapHeight <<endl;
    
    root->Attribute("tilewidth", &this->mTileSize);
    cout << "map tilesize = " << this->mTileSize << endl;
    
    
    
    
    //cout << element->FirstAttribute() << endl;
    
    return false;
}
