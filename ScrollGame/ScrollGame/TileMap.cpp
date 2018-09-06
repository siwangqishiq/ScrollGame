//
//  TileMap.cpp
//  ScrollGame
//
//  Created by panyi  on 2018/9/6.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#include "TileMap.hpp"

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
