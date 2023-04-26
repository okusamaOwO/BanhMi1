#include"class.h"
    void Present(SDL_Renderer* renderer){
        SDL_RenderPresent(renderer);
    }
    void object::init(SDL_Renderer *renderer, string s){
        this-> renderer = renderer ;
        this-> character = loadTexture(s, renderer);
        SDL_QueryTexture(character, NULL, NULL, &frame.h, &frame.w);
    }
    void object::update(){

        SDL_RenderCopy(renderer, character,NULL,&frame);
    }
    void object::changeImageSize(float denta_h, float denta_w){
        frame.h /= denta_h ;
        frame.w/= denta_w ;
    }
    void object::setXY (int x , int y){
        frame.x =x ;
        frame.y =y;
    }
    void object::setSpeed(int speed){
        this->speed = speed ;
    }
    void object::setHp(int hp){
        this->hp = hp ;
    }
    /// cho thanh bien toan cuc a
    void object::changeXY(float &dentaX, float &dentaY){
        frame.x += dentaX*speed ;
        frame.y += dentaY*speed ;
        if(frame.x < 0) dentaX*=-1 ; /// ko cham vao mep trai
        if(frame.x + frame.w > 1200) dentaX *=-1; /// khong cham vao mep phai
        if(frame.y <0) dentaY *= -1 ;/// khong cham vao mep tren
        if(frame.y + frame.h > 750) dentaY *= -1 ;  /// ko cham vao mep duoi

    }
    void object::vibrate(){
            coordinate center ;
            center.x = frame.x + frame.w/2 ;
            center.y = frame.y + frame.h/2 ;
            float denta = 1.16;

            for(int i = 0; i < 2; i++){
            if(i==1) denta = 1/denta ;
            changeImageSize(denta, denta);
            setXY(center.x - frame.w/2, center.y - frame.h/2);
            update();
            Present(renderer);
            SDL_Delay(100);
            }
    }

