#ifndef INDIVIDUALPROJECT_TEXTURE_H
#define INDIVIDUALPROJECT_TEXTURE_H


#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "../utilities/globals.h"
#include "../utilities/constants.h"
#include <SDL_ttf.h>

using namespace std;

/*  
    The following code has been adapted and added to, to suit this programs needs 
    and is no longer identical to the original, however This piece 
    of code was originally from Lazy Foo' Productions
    (http://lazyfoo.net/)
    
    This class is a texture wrapper class for the SDL2 library 
    texture object.
*/
class Texture {
public:
    //Initializes variables
    Texture();

    //Deallocates memory
    ~Texture();

    //Loads image at specified path
    bool loadFromFile(std::string path);

    //Creates a texture from a string of text and a font type
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor,
                              TTF_Font *gFont);

    //Creates blank texture
    bool createBlank(int width, int height,
                     SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    //Set blending
    void setBlendMode(SDL_BlendMode blending);

    //Set alpha modulation
    void setAlpha(Uint8 alpha);

    //Renders texture at given point
    void render(int x, int y,
                SDL_Rect *clip = NULL, double angle = 0.0,
                SDL_Point *center = NULL,
                SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Set self as render target
    void setAsRenderTarget();

    //Gets image dimensions
    int getWidth();
    int getHeight();

    //Pixel manipulators
    bool lockTexture();

    bool unlockTexture();

    void *getPixels();

    void copyPixels(void *pixels);

    int getPitch();

    Uint32 getPixel32(unsigned int x, unsigned int y);

    //WARNING: Will reset the current render target!
    void clearTexture();

private:
    //The actual hardware texture
    SDL_Texture *mTexture;
    void *mPixels;
    int mPitch;

    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif //INDIVIDUALPROJECT_TEXTURE_H
