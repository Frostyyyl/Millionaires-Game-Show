#include "game.hpp"
#include "sprite_object.hpp"


SDL_Renderer* Game::renderer = nullptr;
Sprite s(0, 0);

Game::Game(){}

Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height){
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        isRunning = false;
        std::cout << "Game init error" << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL){
        std::cout << "Window creation error" << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    isRunning = true;
    s.init("dino.jpg");
}

void Game::update(){
    //game update 
    s.update();
}

void Game::handleEvent(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    //drawing everything here
    s.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running(){
    return isRunning;
}