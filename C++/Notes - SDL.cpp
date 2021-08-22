//============================== Setting up Xcode

Header Search Paths:    /usr/local/include
Library Search Paths:   /usr/local/Cellar/sdl2/2.0.8/lib
                        /usr/local/Cellar/sdl2_image/2.0.3/lib


https://wiki.libsdl.org/FrontPage
https://www.libsdl.org/projects/SDL_ttf/docs/SDL_ttf_frame.html
http://lazyfoo.net/tutorials/SDL/index.php

#include "SDL2/SDL.h"


//============================== Initialisation

//-------------------- SDL
SDL_Init(Uint32 flags)      // returns int, if !=0 initialisation failed, 0 for no flags
SDL_Quit()                  // destroys SDL

// flags
SDL_INIT_AUDIO              // audio device management, playback, and recording
SDL_INIT_VIDEO              // Video subsys for creating a window; interfacing with OpenGL, 2D graphics
SDL_INIT_HAPTIC             // Force feedback subsystem
SDL_INIT_GAMECONTROLLER     // Subsystem for supporting controller input devices
SDL_INIT_EVERYTHING         // init flags


//-------------------- Images
int IMG_Init(       // returns a bitmask of all currently initted image loaders
    int flags)

// ussage
IMG_Init( imgFlags ) & imgFlags // returns false on failure

// flags
IMG_INIT_JPG                // ipg images
IMG_INIT_PNG                // png images
IMG_INIT_TIF                // tiff images


//-------------------- Logging
SDL_Log(const char *fmt)    // takes C-style strings



//============================== Display

//-------------------- Window
SDL_Window *mWindow         // holds the graphic window of a game
SDL_CreateWindow(           // returns ptr to a window, if ==nullptr the operation failed
    const char *title,      // title shown in the window bar
    int x, int y,           // coordinates of the top-left corner
    int w, int h,           // width, heigth
    Uint32 flags)           // 0 for no flags

// flags
SDL_WINDOW_FULLSCREEN           // full-screen
SDL_WINDOW_FULLSCREEN_DESKTOP   // full-screen at the current desktop resolution (gnore width/height)
SDL_WINDOW_OPENGL               // add support for the OpenGL graphics library
SDL_WINDOW_RESIZABLE            // allow the user to resize the window

SDL_DestroyWindow(SDL_Window *window)


//-------------------- Renderer
SDL_Renderer *mRenderer     // used for rendering objects on a window
SDL_CreateRenderer(         // returns ptr to a renderer, if ==nullptr the operation failed
    SDL_Window *window,     // ptr to a window to render
    int index,              // which graphics driver to use, -1 SDL decides
    Uint32 flags)           // flags

SDL_DestroyRenderer(SDL_Renderer *renderer)

// falgs
SDL_RENDERER_ACCELERATED    // takes advantege of graphics HW
SDL_RENDERER_PRESENTVSYNC   // enables vertical synchronisation, i.e. wait untill the screen drawes everything before swapping buffers


//-------------------- Colours
SDL_SetRenderDrawColor(     // specifies a colour
    SDL_Renderer *renderer, //
    Uint8 r, Uint8 g,       // 0-255: red, green
    Uint8 b, Uint8 a)       // 0-255: blue, alpha

SDL_RenderClear(            // clears the screen to a specified colour
    SDL_Renderer *renderer) //

SDL_RenderPresent(          // swap the front and back buffers
    SDL_Renderer *renderer) //

//-------------------- Rectangles
SDL_Rect rectangle =        // definition of a rectangle
    {int x, int y, int w, int h,}

SDL_RenderFillRect(         // draw a rectangle to a render
    SDL_Renderer *renderer,
    const SDL_Rect *rect)

int SDL_FillRect(           // perform a fast fill of a rectangle with a specific color
    SDL_Surface *dst,       // destination
    const SDL_Rect *rect,   // rectangle to fill, nullptr to fill the entire sruface
    Uint32 color)

Uint32 SDL_MapRGBA(
    const SDL_PixelFormat* format,
    Uint8 r,
    Uint8 g,
    Uint8 b,
    Uint8 a)

//-------------------- Images
SDL_Surface *SDL_GetWindowSurface(
    SDL_Window *window)

int SDL_UpdateWindowSurface(    // returns 0 (success) or a negative code (failure)
    SDL_Window *window)

int SDL_UpdateWindowSurfaceRects(   // copy areas of the window surface to the screen
    SDL_Window *window,
    const SDL_Rect *rects,          // an array of rectangles to be copied
    int numrects)                   // number of restangles

SDL_Surface *surface            // declares a ptr to a surface

SDL_Surface* SDL_CreateRGBSurface(
    Uint32 flags,                   // obsolete, should be 0
    int width, int height,
    int depth,                      // depth of the surface in bits, usually 32
    Uint32 Rmask, Uint32 Gmask,
    Uint32 Bmask, Uint32 Amask)

SDL_Surface* SDL_CreateRGBSurfaceWithFormat(
    Uint32 flags,       // obsolete, should be 0
    int    width,
    int    height,
    int    depth,       // number of bits ber pixel, usually 32
    Uint32 format)      // the pixel format

int SDL_BlitSurface(            // perform a fast surface copy to a destination surface
    SDL_Surface *src,           // to be copied from
    const SDL_Rect *srcrect,    // rect to be copied, nullptr for entire surface
    SDL_Surface *dst,           // destination surface
    SDL_Rect *dstrect)          // rect to be copied into

SDL_Surface *SDL_ConvertSurface(    // returns optimized surface
    SDL_Surface *src,               // surface to optimize
    const SDL_PixelFormat *fmt,     // structure to optimize for
    Uint32 flags)                   // always 0 (leftover from an older version)

SDL_Surface *SDL_LoadBMP(
    const char* file)

void SDL_FreeSurface(           // free an RGB surface
    SDL_Surface *surface)       // surfact to get rid of

//-------------------- Textures
SDL_Surface *IMG_Load(const char *file) // returns nullptr it failed

SDL_Texture *SDL_CreateTextureFromSurface(  // create texture from an existing surface
    SDL_Renderer *renderer,                 // rendering context
    SDL_Surface *surface)                   // pixel data used to fill the texture

SDL_QueryTexture(               // get parameters of a texture:
    SDL_Texture *texture,
    Uint32 *format,
    int *access,
    int *w,
    int *h)

int SDL_RenderCopy(             // returns 0 on success, negative value on failure
    SDL_Renderer *renderer,
    SDL_Texture *texture,       // texture to draw
    const SDL_Rect *srcrect,    // part of texture to draw (null if whole)
    const SDL_Rect *dstrect)    // rectangle to draw onto the target

SDL_RenderCopyEx(
    SDL_Renderer *renderer,
    SDL_Texture *texture,       // texture to draw
    const SDL_Rect *srcrect,    // part of texture to draw (nullptr if whole)
    const SDL_Rect *dstrect,    // rectangle to draw onto the target
    const double angle,         // rotation angle (in degrees, clockwise)
    const SDL_Point *center,    // point to rotate about (nullptr for center)
    const SDL_RendererFlip flip)// how to flip texture (usually SDL_FLIP_NONE)


//============================== Input

//-------------------- Keyboard
SDL_GetKeyboardState(int *numkeys)  // returns a pointer to an array of current state of the keyboard
// SDL_SCANCODEs used to index keyboard state
SDL_SCANCODE_ESCAPE

// example
Uint8 *state = SDL_GetKeyboardState(NULL)   // read the keyboard state
state[SDL_SCANCODE_ESCAPE]                  // bool, check if ESC was pressed


//-------------------- Events
SDL_PollEvent(SDL_Event *event)     // returns true if event in queue, removes it and stores it in event
SDL_Event event     // an event object
SDL_QUIT            // an event .type

/example
while (SDL_PollEvent(&event)) {
    switch (event.type) {...;}}




//============================== Chapter

//-------------------- Section
