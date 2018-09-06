// ============================================================================
// [Include Section]
// ============================================================================
#include "CApp.h"

// ============================================================================
// [Defines & Constants]
// ============================================================================
#define APPTITLE 		"SDL2 Template Program"

const int SCREEN_WIDTH 	= 800;
const int SCREEN_HEIGHT	= 600;


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
	// Initialize the SDL library.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "SDL_Init() failed: %s\n", SDL_GetError());
		return APP_FAILED;
	}
	
	window = SDL_CreateWindow(APPTITLE, 
							  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
							  SCREEN_WIDTH, SCREEN_HEIGHT, 
							  SDL_WINDOW_SHOWN);

	if (window != NULL) {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        m_vscreen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);
	}
	
	// Success
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
			}
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
    SDL_SetRenderTarget(renderer, m_vscreen);

	// Do your drawing here
//    SDL_RenderClear(renderer);
//    SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff);
//    SDL_Rect rect;
//    rect.x = rect.y = 0;
//    rect.w = rect.h = 100;
//    SDL_RenderFillRect(renderer, &rect);
//    SDL_RenderPresent(renderer);
//
//    //SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
//    SDL_RenderCopy(renderer, m_vscreen, nullptr, nullptr);
//    SDL_RenderPresent(renderer);
    
    SDL_Rect r;
    r.x = r.y = 0;
    r.w = r.h = 50;
    
    SDL_SetRenderTarget(renderer, m_vscreen);
    
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
    SDL_RenderDrawRect(renderer,&r);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(renderer, &r);
    SDL_RenderDrawLine(renderer, 0, 0, 100, 100);
    
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, m_vscreen, NULL, NULL);
    SDL_RenderPresent(renderer);
}

SDL_Texture *loadImage(std::string file)
{
    
    return nullptr;
}

