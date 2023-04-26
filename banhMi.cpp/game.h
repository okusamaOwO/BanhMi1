#ifndef GAME__H_
#define GAME__H_

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include<conio.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>


using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 750;
const string WINDOW_TITLE = "Window"; // tên cửa sổ

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
SDL_Texture* loadTexture( string path,SDL_Renderer* renderer );
#endif // GAME__H_
