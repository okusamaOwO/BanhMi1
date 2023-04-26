#ifndef CLASS__H_
#define CLASS__H_
#include"game.h"

void Present(SDL_Renderer* renderer);
struct coordinate{
    int x;
    int y ;
};

class object{
public:
    SDL_Texture * character;
    SDL_Rect frame;
    SDL_Renderer* renderer;
    int speed ;
    int hp ;
    int damage ;
    string path;
    int x,y,w,h ;
    object(){
        this->x = frame.x;
        this->y = frame.y;
        this->w = frame.w;
        this->h = frame.h;
    }
    void init(SDL_Renderer *renderer, string s);
    void update();
    void changeImageSize(float denta_h, float denta_w);
    void setXY (int x , int y);
    void setSpeed(int speed);
    void setHp(int hp);
    void changeXY(float &dentaX, float &dentaY);
    void vibrate();
    ///void AisCenterOfB(egg&a, chicken &b);
};

#endif //CLASS__H_
