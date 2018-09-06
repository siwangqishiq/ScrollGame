//
//  ImageLoad.hpp
//  ScrollGame
//
//  Created by panyi  on 2018/9/5.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#ifndef ImageLoad_hpp
#define ImageLoad_hpp

#include <stdio.h>
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <map>

class ImageLoad
{
public:
    static ImageLoad *getInstance(){
        if(m_instance == nullptr)
            m_instance = new ImageLoad();
        //memcpy(dst , src , size_t)
        return m_instance;
    }
    
private:
    ImageLoad();
    std::map<std::string,SDL_Texture *> m_textures;
    
    static ImageLoad* m_instance;
};
#endif /* ImageLoad_hpp */
