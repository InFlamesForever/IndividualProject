#include "Texture.h"

Texture::Texture() {
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
    mPixels = NULL;
    mPitch = 0;
}

Texture::~Texture() {
    //Deallocate
    free();
}

bool Texture::loadFromFile(std::string path) {
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture *newTexture = NULL;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        cout << "Unable to load image %s! SDL_image Error: %s" << path.c_str()
        << IMG_GetError() << endl;
    }
    else {
        //Convert surface to display format
        SDL_Surface *formattedSurface = SDL_ConvertSurfaceFormat(
                loadedSurface, SDL_PIXELFORMAT_RGBA8888, NULL);
        if (formattedSurface == NULL) {
            cout << "Unable to convert loaded surface to display format! %s"
            << SDL_GetError() << endl;
        }
        else {
            //Create blank streamable texture
            newTexture = SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA8888,
                                           SDL_TEXTUREACCESS_STREAMING,
                                           formattedSurface->w,
                                           formattedSurface->h);
            if (newTexture == NULL) {
                cout << "Unable to create blank texture! SDL Error: %s"
                << SDL_GetError() << endl;
            }
            else {
                //Enable blending on texture
                SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);

                //Lock texture for manipulation
                SDL_LockTexture(newTexture, &formattedSurface->clip_rect,
                                &mPixels, &mPitch);

                //Copy loaded/formatted surface pixels
                memcpy(mPixels, formattedSurface->pixels,
                       (size_t) (formattedSurface->pitch * formattedSurface->h));

                //Get image dimensions
                mWidth = formattedSurface->w;
                mHeight = formattedSurface->h;

                //Get pixel data in editable format
                Uint32 *pixels = (Uint32 *) mPixels;
                int pixelCount = (mPitch / 4) * mHeight;

                //Map colors
                Uint32 colorKey = SDL_MapRGB(formattedSurface->format, 0, 0xFF,
                                             0xFF);
                Uint32 transparent = SDL_MapRGBA(formattedSurface->format, 0x00,
                                                 0xFF, 0xFF, 0x00);

                //Color key pixels
                for (int i = 0; i < pixelCount; ++i) {
                    if (pixels[i] == colorKey) {
                        pixels[i] = transparent;
                    }
                }

                //Unlock texture to update
                SDL_UnlockTexture(newTexture);
                mPixels = NULL;
            }

            //Get rid of old formatted surface
            SDL_FreeSurface(formattedSurface);
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

bool Texture::createBlank(int width, int height,
                          SDL_TextureAccess access) {
    //Create uninitialized texture
    mTexture = SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA8888, access,
                                 width, height);
    if (mTexture == NULL) {
        cout << "Unable to create blank texture! SDL Error: %s"
        << SDL_GetError() << endl;
    }
    else {
        mWidth = width;
        mHeight = height;
    }

    return mTexture != NULL;
}

void Texture::free() {
    //Free texture if it exists
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
        mPixels = NULL;
        mPitch = 0;
    }
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    //Modulate texture rgb
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
    //Set blending function
    SDL_SetTextureBlendMode(mTexture, blending);
}

void Texture::setAlpha(Uint8 alpha) {
    //Modulate texture alpha
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Texture::render(int x, int y,
                     SDL_Rect *clip, double angle,
                     SDL_Point *center, SDL_RendererFlip flip) {

    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};

    //Set clip rendering dimensions
    if (clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center,
                     flip);
}

void Texture::setAsRenderTarget() {
    //Make self render target
    SDL_SetRenderTarget(gRenderer, mTexture);
}

int Texture::getWidth() {
    return mWidth;
}

int Texture::getHeight() {
    return mHeight;
}

bool Texture::lockTexture() {
    //Texture is already locked
    if (mPixels != NULL) {
        cout << "Texture is already locked!" << endl;
        return false;
    }
        //Lock texture
    else {
        if (SDL_LockTexture(mTexture, NULL, &mPixels, &mPitch) != 0) {
            cout << "Unable to lock texture! %s" << SDL_GetError() << endl;
            return false;
        }
    }

    return true;
}

bool Texture::unlockTexture() {
    bool success = true;

    //Texture is not locked
    if (mPixels == NULL) {
        cout << "Texture is not locked!" << endl;
        success = false;
    }
        //Unlock texture
    else {
        SDL_UnlockTexture(mTexture);
        mPixels = NULL;
        mPitch = 0;
    }

    return success;
}

void *Texture::getPixels() {
    return mPixels;
}

void Texture::copyPixels(void *pixels) {
    //Texture is locked
    if (mPixels != NULL) {
        //Copy to locked pixels
        memcpy(mPixels, pixels, (size_t) (mPitch * mHeight));
    }
}

int Texture::getPitch() {
    return mPitch;
}

Uint32 Texture::getPixel32(unsigned int x, unsigned int y) {
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *) mPixels;

    //Get the pixel requested
    return pixels[(y * (mPitch / 4)) + x];
}

SDL_Texture *Texture::getTexture() {
    return mTexture;
}


void Texture::setTexture(SDL_Texture *text) {
    mTexture = text;

}
