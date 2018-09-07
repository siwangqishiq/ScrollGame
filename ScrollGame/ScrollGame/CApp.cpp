// ============================================================================
// [Include Section]
// ============================================================================
#include "CApp.h"

#include <iostream>
// ============================================================================
// [Defines & Constants]
// ============================================================================
#define APPTITLE 		"Scroll"

const int SCREEN_WIDTH 	= 800;
const int SCREEN_HEIGHT	= 600;

const int WORLD_WIDTH     = 1920;
const int WORLD_HEIGHT    = 1200;


CApp::CApp() :
	running(false)
{
    
}

CApp::~CApp()
{
	OnCleanup();
}

int CApp::OnInit()
{
    
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "SDL_Init() failed: %s\n", SDL_GetError());
		return APP_FAILED;
	}
    
    IMG_Init(IMG_INIT_PNG);
	
	window = SDL_CreateWindow(APPTITLE, 
							  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
							  SCREEN_WIDTH, SCREEN_HEIGHT, 
							  SDL_WINDOW_SHOWN);

	if (window != NULL) {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        m_vscreen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
	}
    
    
    mBackgroundTexture = ImageLoad::load_image(renderer, "timg.png");
	// Success
    float r = (float)SCREEN_WIDTH / SCREEN_HEIGHT;
    mCamera = new Camera(SCREEN_WIDTH , SCREEN_HEIGHT , r , WORLD_WIDTH , WORLD_HEIGHT);
    
	return APP_OK;
}

void CApp::OnCleanup()
{
	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);	
	}
	if (window != NULL)	{
		SDL_DestroyWindow(window);
	}
    
    if(mBackgroundTexture != nullptr)
    {
        SDL_DestroyTexture(mBackgroundTexture);
    }
    
    
    if(m_vscreen != nullptr){
        SDL_DestroyTexture(m_vscreen);
    }

	SDL_Quit();
}

int CApp::OnExecute()
{
	// Initialize application.
	int state = OnInit();
	if (state != APP_OK) {
		return state;
	}
	
	// Enter the SDL event loop.
	SDL_Event event;

	running = true;
	
	while (running)
	{
		while (SDL_PollEvent(&event)) {
        	OnEvent(&event);
        }
		
		OnUpdate();
		OnRender();
	}
	
	return state;
}

void CApp::OnEvent(SDL_Event* event)
{
	switch (event->type)
	{
		case SDL_QUIT:
			running = false;
			break;
		case SDL_KEYDOWN:
			if (event->key.keysym.sym == SDLK_ESCAPE) {
				running = false;
            }else if(event->key.keysym.sym == SDLK_RIGHT){
                mCamera->toRight();
            }else if(event->key.keysym.sym == SDLK_LEFT){
                mCamera->toLeft();
            }else if(event->key.keysym.sym == SDLK_UP){
                mCamera->toUp();
            }else if(event->key.keysym.sym == SDLK_DOWN){
                mCamera->toDown();
            }else if(event->key.keysym.sym == SDLK_w){
                mCamera->moveFar();
            }else if(event->key.keysym.sym == SDLK_s){
                mCamera->moveNear();
            }
            break;
		default:
			break;
	}
}

void CApp::OnUpdate()
{
	// Update your game logic here
}

void CApp::OnRender()
{
    //SDL_SetRenderTarget(renderer, m_vscreen);

	// Do your drawing here
    
//    SDL_RenderClear(renderer);
//    SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff);
//    SDL_Rect rect;
//    rect.x = rect.y = 0;
//    rect.w = rect.h = 100;
//    SDL_RenderFillRect(renderer, &rect);
//    SDL_RenderPresent(renderer);

//    //SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
//    SDL_RenderCopy(renderer, m_vscreen, nullptr, nullptr);
//    SDL_RenderPresent(renderer);
    
    SDL_Rect r;
    r.x = r.y = 0;
    r.w = r.h = 50;
    
    SDL_SetRenderTarget(renderer, m_vscreen);
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
    
    //SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
    //SDL_RenderDrawLine(renderer, 0, 0, 90, 90);
    //SDL_RenderCopy(renderer, mBackgroundTexture, nullptr, nullptr);
    
    SDL_Rect srcBgRect;
    //SDL_Rect dstBgRect;
    srcBgRect.x = mCamera->mLeft;
    srcBgRect.y = mCamera->mTop;
    srcBgRect.w = mCamera->mViewWidth;
    srcBgRect.h = mCamera->mViewHeight;
    
    std::cout << mCamera->mLeft << std::endl;
    
    SDL_RenderCopy(renderer, mBackgroundTexture, &srcBgRect, nullptr);
    
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, m_vscreen, NULL, NULL);
    SDL_RenderPresent(renderer);
}

