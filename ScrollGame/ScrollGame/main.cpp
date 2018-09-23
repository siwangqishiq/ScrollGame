// ============================================================================
// [Include Section]
// ============================================================================
#include "CApp.h"
#include "b64.h"
#include <iostream>


//#define TIXML_USE_STL
#include "TileMap.hpp"
#include <stdio.h>

using namespace std;

// ============================================================================
// [Entry-Point]
// ============================================================================
int main(int argc, char* argv[])
{
//    std::string raw = "AQAAAAAAAAACAAAABAAAAAQAAAAAAAAAAAAAAAAAAAAFAAAABgAAAAAAAAAAAAAAAAAAAAkAAAAKAAAAAwAAAAMAAAADAAAAAwAAAAMAAAA=";
//
//    unsigned char *map_data = b64_decode(raw.c_str(), raw.size());
//    std::string s((char *)data_str);
//    cout << data_str <<endl;
//
//    int width = 5;
//    int height = 4;
//    int data[width * height];
//
//    cout << "raw size = " << width * height * sizeof(int) << endl;
//
//    memcpy(&data, data_str, width * height * sizeof(int));
//
//    for(int i = 0 ;i < height ;i++)
//    {
//        for(int j = 0;j< width ;j++)
//        {
//            cout << data[width * i + j] << "   ";
//        }//end for j
//        cout << endl;
//    }//end for i
    
    TileMap tileMap;
    cout << "result = " <<tileMap.loadMap(string("/Users/panyi/maro.tmx")) << endl;
    
    
//    CApp app;
//    return app.OnExecute();
    
    return 0;
}




