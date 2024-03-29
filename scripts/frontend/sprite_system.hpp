#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "object_system.hpp"
#include "text.hpp"

class Sprite : public Object{
protected: // protected because we need it for spritesheet
    int width, height; 
    SDL_Rect src, dest;
    SDL_Texture* tex;
public:
    Sprite(const char* filename, int x, int y);
    void draw() override;
    void update() override;
    void destroy() override;
    int getWidth();
    int getHeight();
    SDL_Rect& getPosition();
};

class Spritesheet : public Sprite{
private:
    int numOfColumns, numOfRows;
    int spriteWidth = width / numOfColumns;
    int spriteHeight = height / numOfRows;
public:
    Spritesheet(const char* filename, int x, int y, int numOfColumns = 2, int numOfRows = 1);
    void updateSprite(int row = 0, int col = 0);
    int getWidth();
    int getHeight();
};

class TextSprite : public Spritesheet{
private: 
    Text contents;
    TTF_Font* font;
    SDL_Texture* textTexture;
    static const int MOVE_HORIZONTALLY = 10;
    static const int MOVE_VERTICALLY = -4;
public:
    TextSprite(const char* filename, int x, int y, std::string data, int numOfColumns = 1, int numOfRows = 1);
    void loadData(std::string data);
    void draw() override;
    void destroy() override;
};

class DoubleTextsprite : public Spritesheet{
private:
    std::string flush;
    Text contents;
    Text prefix;
    TTF_Font* font;
    SDL_Texture* textTexture;
    static const int ALIGN = 3;
    static const int MOVE_HORIZONTALLY = 10;
    static const int MOVE_VERTICALLY = -3;
public:
    DoubleTextsprite(const char* filename, int x, int y, std::string prefixData, std::string data, std::string flush = "left",
                    int numOfColumns = 1, int numOfRows = 1);
    void loadData(std::string data);

    void draw() override;
    void destroy() override;
};

class MultipleTextSprite : public Spritesheet{
private:
    Text contentsA;
    Text contentsB;
    Text contentsC;
    Text contentsD;
    TTF_Font* font;
    SDL_Texture* textTexture;
    static const int MOVE_HORIZONTALLY = 10;
    static const int MOVE_VERTICALLY = 0;
public:
    MultipleTextSprite(const char* filename, int x, int y, std::string A, std::string B, std::string C, std::string D, 
                        int numOfColumns = 1, int numOfRows = 1);
    MultipleTextSprite(const char* filename, int x, int y, std::string A, std::string B, 
            int numOfColumns = 1, int numOfRows = 1);
    void loadData(std::string A, std::string B);
    void loadData(std::string A, std::string B, std::string C, std::string D);
    void draw() override;
    void destroy() override;
};