#pragma once
#include "SDL_TTF.h"
#include "scene_manager.hpp"
#include "text.hpp"

class TextManager{
private:
    TextManager(){};
    const char* fontFilename = "fonts/muli.ttf";
    TTF_Font* hugeFont;
    TTF_Font* largeFont;
    TTF_Font* mediumFont;
    TTF_Font* smallFont;
public:
    static TextManager& getInstance(){
        static TextManager INSTANCE;
        return INSTANCE;
    }
    TTF_Font* loadFont(const char* fontFilename, int fontSize){
        TTF_Font* font = TTF_OpenFont(fontFilename, fontSize);
        if (!font) {
            std::cerr << "ERROR: Failed to load font: " << TTF_GetError() << std::endl;
        }
        return font;
    }
    SDL_Texture* loadText(TTF_Font* font, Text &contents, Text &prefix, SDL_Rect &dest){
        SDL_Surface* tempSurface = SDL_CreateRGBSurface(0, dest.w, dest.h, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
        SDL_Surface* prefixSurface = TTF_RenderText_Blended_Wrapped(mediumFont, prefix.text.c_str(), {125, 23, 78}, prefix.dest.w);
        SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font, contents.text.c_str(), {12, 15, 10}, contents.dest.w);
        if (!tempSurface){
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!textSurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!prefixSurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        }
        if (SDL_BlitSurface(prefixSurface, NULL, tempSurface, &prefix.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces"; 
        } if (SDL_BlitSurface(textSurface, NULL, tempSurface, &contents.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces" << std::endl;
        }
        SDL_Texture* tex = SDL_CreateTextureFromSurface(SceneManager::renderer, tempSurface);
        if (!tex) {
            std::cerr << "ERROR: Failed to create text texture: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(tempSurface);
        SDL_FreeSurface(prefixSurface);
        SDL_FreeSurface(textSurface);

        return tex;
    }
    SDL_Texture* loadText(TTF_Font* font, Text &contents, SDL_Rect &dest){
        SDL_Surface* tempSurface = SDL_CreateRGBSurface(0, dest.w, dest.h, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
        SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font, contents.text.c_str(), {12, 15, 10}, contents.dest.w);
        if (!tempSurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!textSurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        }
        if (SDL_BlitSurface(textSurface, NULL, tempSurface, &contents.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces"; 
        }
        SDL_Texture* tex = SDL_CreateTextureFromSurface(SceneManager::renderer, tempSurface);
        if (!tex) {
            std::cerr << "ERROR: Failed to create text texture: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(tempSurface);
        SDL_FreeSurface(textSurface);

        return tex;
    }
    SDL_Texture* loadText(Text &A, Text &B, SDL_Rect &dest){
        SDL_Surface* tempSurface = SDL_CreateRGBSurface(0, dest.w, dest.h, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
        SDL_Surface* ASurface = TTF_RenderText_Blended_Wrapped(largeFont, A.text.c_str(), {12, 15, 10}, A.dest.w);
        SDL_Surface* BSurface = TTF_RenderText_Blended_Wrapped(largeFont, B.text.c_str(), {12, 15, 10}, B.dest.w);
        if (!tempSurface){
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!ASurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!BSurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        }
        if (SDL_BlitSurface(ASurface, NULL, tempSurface, &A.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces"; 
        } if (SDL_BlitSurface(BSurface, NULL, tempSurface, &B.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces" << std::endl;
        }
        SDL_Texture* tex = SDL_CreateTextureFromSurface(SceneManager::renderer, tempSurface);
        if (!tex) {
            std::cerr << "ERROR: Failed to create text texture: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(tempSurface);
        SDL_FreeSurface(ASurface);
        SDL_FreeSurface(BSurface);

        return tex;
    }
    SDL_Texture* loadText(Text &A, Text &B, Text &C, Text &D, SDL_Rect &dest){
        SDL_Surface* tempSurface = SDL_CreateRGBSurface(0, dest.w, dest.h, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
        SDL_Surface* ASurface = TTF_RenderText_Blended_Wrapped(largeFont, A.text.c_str(), {12, 15, 10}, A.dest.w);
        SDL_Surface* BSurface = TTF_RenderText_Blended_Wrapped(largeFont, B.text.c_str(), {12, 15, 10}, B.dest.w);
        SDL_Surface* CSurface = TTF_RenderText_Blended_Wrapped(largeFont, C.text.c_str(), {12, 15, 10}, C.dest.w);
        SDL_Surface* DSurface = TTF_RenderText_Blended_Wrapped(largeFont, D.text.c_str(), {12, 15, 10}, D.dest.w);
        if (!tempSurface){
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!ASurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!BSurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!CSurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        } if (!DSurface) {
            std::cerr << "ERROR: Failed to render text surface: " << TTF_GetError() << std::endl;
        }
        if (SDL_BlitSurface(ASurface, NULL, tempSurface, &A.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces"; 
        } if (SDL_BlitSurface(BSurface, NULL, tempSurface, &B.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces" << std::endl;
        } if (SDL_BlitSurface(CSurface, NULL, tempSurface, &C.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces"; 
        } if (SDL_BlitSurface(DSurface, NULL, tempSurface, &D.dest) == -1){
            std::cerr << "ERROR: Failed to merge surfaces" << std::endl;
        }
        SDL_Texture* tex = SDL_CreateTextureFromSurface(SceneManager::renderer, tempSurface);
        if (!tex) {
            std::cerr << "ERROR: Failed to create text texture: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(tempSurface);
        SDL_FreeSurface(ASurface);
        SDL_FreeSurface(BSurface);
        SDL_FreeSurface(CSurface);
        SDL_FreeSurface(DSurface);

        return tex;
    }
    void draw(SDL_Texture* tex, SDL_Rect &dest){
        SDL_RenderCopy(SceneManager::renderer, tex, NULL, &dest); 
    }
    void init(){
        hugeFont = loadFont(fontFilename, 46);
        largeFont = loadFont(fontFilename, 32);
        mediumFont = loadFont(fontFilename, 21);
        smallFont = loadFont(fontFilename, 16);
    }
    TTF_Font* getHugeFont(){ return hugeFont; }
    TTF_Font* getLargeFont(){ return largeFont; }
    TTF_Font* getMediumFont(){ return mediumFont; }
    TTF_Font* getSmallFont(){ return smallFont; }

};