//
//  TileMap.cpp
//  ScrollGame
//
//  Created by panyi  on 2018/9/6.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#include "TileMap.hpp"
#include "tinyxml.h"
#include "b64.h"
#include <iostream>

using namespace std;

void TileMap::update()
{
    for(Layer *player : mLayers)
    {
        player->update();
    }//end for each
}


void TileMap::render()
{
    for(Layer *player : mLayers)
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
    
    
    
    for(TiXmlElement *e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        //cout << e->Value() << endl;
        if(e->Value() == string("tileset")){
            parseTileset(e);
        }
        else if(e->Value() == string("layer"))//parse layer
        {
            parseLevel(e);
        }
    }//end for e
    
    
    //cout << element->FirstAttribute() << endl;
    return false;
}

bool TileMap::parseLevel(TiXmlElement *e)
{
    if(e == nullptr)
        return false;
    
    int w,h;
    e->Attribute("width",  &w);
    e->Attribute("height" , &h);
    
    Layer *pLayer = new Layer(w , h);
    pLayer->setName(e->Attribute("name"));
    
    //cout << "name = " <<pLayer->getName() << " w = " << pLayer->getWidth() << " , h = " << pLayer->getHeight() <<endl;
    
    TiXmlElement *dataNode = e->FirstChildElement();
    string mapDataRaw;
    if(dataNode->Value() == string("data"))
    {
        TiXmlNode *textNode = dataNode->FirstChild();
        TiXmlText *text = textNode->ToText();
        mapDataRaw = text->Value();
        //cout << "data = " << s << endl;
    }
    
    unsigned char *mapData = b64_decode(mapDataRaw.c_str(), mapDataRaw.size());
    string mapDataStr = string((char *)mapData);
    memcpy(pLayer->data, mapData, w * h * sizeof(int));
    
    cout << "name = " <<pLayer->getName() << " w = " << pLayer->getWidth() << " , h = " << pLayer->getHeight() <<endl;
//    for(int i = 0 ; i < pLayer->getHeight() ; i++){
//        for(int j = 0; j < pLayer->getWidth() ; j++){
//            int val = pLayer->data[i * pLayer->getWidth() + j];
//            cout << val << "  ";
//        }
//        cout << endl;
//    }
    
    this->mLayers.push_back(pLayer);
    
    return true;
}


bool TileMap::parseTileset(TiXmlElement *tilesetElement){
    if(tilesetElement == nullptr)
        return false;
    
    tilesetElement->Attribute("firstgid" , &this->mTileSet.firstgid);
    this->mTileSet.name = tilesetElement->Attribute("name");
    tilesetElement->Attribute("tilewidth" , &this->mTileSet.tileWidth);
    tilesetElement->Attribute("tileheight" , &this->mTileSet.tileHeight);
    tilesetElement->Attribute("tilecount" , &this->mTileSet.tilecount);
    tilesetElement->Attribute("columns" , &this->mTileSet.columns);
    
    cout << "firstgid = " << this->mTileSet.firstgid << " name = " << mTileSet.name
    << endl;
    cout << "tilewidth = " << this->mTileSet.tileWidth << " tileheiht = " << mTileSet.tileHeight
    << endl;
    cout << "tilecount = " << this->mTileSet.tilecount << " columns = " << mTileSet.columns
    << endl;
    
    for(TiXmlElement *e = tilesetElement->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement())
    {
        cout << e->Value() << endl;
        
        if(e->Value() == string("image"))//parse image resource
        {
            this->mTileSet.imagePath = e->Attribute("source");
            e->Attribute("width" , &this->mTileSet.imageWidth);
            e->Attribute("height" , &this->mTileSet.imageHeight);
            cout << "image = " << this->mTileSet.imagePath << "  w = " << mTileSet.imageWidth << " h = " << mTileSet.imageHeight << endl;
        }
        else if(e->Value() == string("tile")) //parse tile
        {
            Tile t;
            e->Attribute("id" , &t.id);
            TiXmlElement* propertiesElem = e->FirstChildElement();
            
            for(TiXmlElement *pros = propertiesElem->FirstChildElement() ;  pros != nullptr ;pros = pros->NextSiblingElement()){
                //cout << " property name is " << pros->Attribute("name") << endl;
                if(pros->Attribute("name") == string("ishit")){
                    pros->Attribute("value", &t.ishit);
                }
            }
            //cout << "tile : " << t.id << "   " << t.ishit << endl;
            mTileSet.tiles[t.id] = t;
        }
    }//end for e
    
//    for(std::pair<int, Tile> p : mTileSet.tiles){
//        cout << p.first << " = " << "{ " << p.second.id << " , " << p.second.ishit << " } " << endl;
//    }
    
    return true;
}

void Layer::update(){
    
}

void Layer::render(){
    
}
