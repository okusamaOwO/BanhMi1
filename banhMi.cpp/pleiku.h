#ifndef PLEIKU__H_
#define PLEIKU__H_
#include"game.h"
#include"class.h"
#include"chicken.h"
#include"egg.h"
#include"ImpTimer.h"
#include"drumStick.h"
#include"menu.h"
#include"textObject.h"
    void play();
    SDL_Texture* initBg(SDL_Renderer* renderer);
    void initRocket(object& rk, SDL_Renderer* renderer);
    void handle(object obj[],
                vector <chicken> &v,
                SDL_Renderer* renderer,
                 SDL_Event g_event,
                 vector<egg> &eggs,
                 textObject time_game,
                 TTF_Font* font_time,
                 textObject score_text);



#endif // PLEIKU__H_
