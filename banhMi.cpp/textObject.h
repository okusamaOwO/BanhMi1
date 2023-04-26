#ifndef TEXTOBJECT__H_
#define TEXTOBJECT__H_
#include"game.h"

class textObject{
public:
    string str_val_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;

    textObject(){
    text_color_.r = 255;
    text_color_.g = 255;
    text_color_.b = 255;
    texture_ = nullptr ;
    }
    ///~textObject();
    /**
    enum TextColor{
        RED_TEXT = 0 ;
        WHITE_TEXT = 1;
        BLACK_TEXT = 2 ;
    };
    **/
    bool LoadFromFile(string path);
    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen){
         SDL_Surface* text_surface = TTF_RenderText_Solid(font, str_val_.c_str(), text_color_);
        if(text_surface)
        {
        texture_ = SDL_CreateTextureFromSurface(screen, text_surface);
        width_ = text_surface->w ;
        height_ = text_surface->h;
        SDL_FreeSurface(text_surface);
        }
    return texture_!= NULL;
    }
    void Free();
    void SetColor(Uint8 red, Uint8 green, Uint8 blue);
    void SetColor(int type);
    void RenderText(SDL_Renderer* screen,
                    int xp,int yp,
                    SDL_Rect* clip = NULL,
                    double angle = 0.0,
                    SDL_Point* center = NULL,
                    SDL_RendererFlip flip = SDL_FLIP_NONE){

         SDL_Rect renderQuad = {xp,yp,width_, height_};
         if(clip != nullptr){
            renderQuad.w = clip->w ;
            renderQuad.h = clip->h;
         }
         SDL_RenderCopyEx(screen, texture_, clip, &renderQuad, angle, center, flip);

    }
    int GetWidth()const{
        return this->width_;
    }
    int GetHeight()const{
    return this->height_;
    }

    void SetText(const string& text){
        str_val_ = text ;
    }
    string GetText()const{
        return str_val_;
    }
};

#endif // TEXTOBJECT__H_
