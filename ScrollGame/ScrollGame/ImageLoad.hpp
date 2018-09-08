//
//  ImageLoad.hpp
//  ScrollGame
//
//  Created by panyi  on 2018/9/5.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#ifndef ImageLoad_hpp
#define ImageLoad_hpp

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif
#include <map>
#include <string>

class ImageLoad
{
public:
    static ImageLoad *getInstance(){
        if(m_instance == nullptr)
            m_instance = new ImageLoad();
        //memcpy(dst , src , size_t)
        return m_instance;
    }
    
    static SDL_Surface *load_png_image(std::string filename){
        if(filename.size() == 0)
            return nullptr;
        
        SDL_Surface *image = IMG_Load(filename.c_str());
        return image;
    }
    
    static SDL_Texture *load_image(SDL_Renderer *render , std::string filename){
        SDL_Surface *surface = load_png_image(filename);
        SDL_Texture *texture = nullptr;
        if(surface != nullptr){
            texture = SDL_CreateTextureFromSurface(render, surface);
            SDL_FreeSurface(surface);
        }
        
        return texture;
    }
    
private:
    ImageLoad();
    std::map<std::string,SDL_Texture *> m_textures;
    
    static ImageLoad* m_instance;
    
    
};
#endif /* ImageLoad_hpp */
