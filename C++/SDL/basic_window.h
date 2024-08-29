#include <SDL2/SDL.h>
#include <iostream>

// Window* window = new Window();
// window->start("hello world");
// window->update();
// delete window;

#if defined(__MINGW32__) || defined(__MINGW64__)
    #undef main
#endif

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH  600

class Window {
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Event event;
    bool isRunning = true;
    void clear() 
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
public:
    void start(const char* title)
    {
        #if defined SCREEN_WIDTH && defined SCREEN_HEIGHT
            window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        #else
            window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,0);
        #endif
        if(window == NULL) 
        {
            std::cout << "window could not initialized"<<std::endl;
        }
        surface = SDL_GetWindowSurface(window);
        if(surface == NULL) {
            std::cout << "Surface can not initialized"<<std::endl;
        }
    }
    void update() 
    {
        while(isRunning) 
        {
            SDL_FillRect(surface,NULL,0x00000000);
            SDL_UpdateWindowSurface(window);
            handleEvents();
        }
        
    }
    void handleEvents() {
        while(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
            }
        }
    }
    Window() {
        if(SDL_Init(SDL_INIT_VIDEO)) 
        {
            std::cout << "SDL are initialized"<<"\n";
        }
    }
    ~Window() {
        clear();
    }
};
