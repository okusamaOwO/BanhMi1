#include"pleiku.h"

SDL_Texture* initBg(SDL_Renderer* renderer){
    string s1 = "./pictures//bgg.png";
    SDL_Texture* bg = loadTexture(s1,renderer);
    SDL_RenderCopy(renderer, bg,NULL,NULL);
}
void initDrumStick(drumStick &ds, SDL_Renderer* renderer){

    string s = "./pictures//drumStick.png";
    ds.init(renderer,s);
    ds.changeImageSize(30,30);
    ds.setSpeed(4);
}
void initRocket(object &rk, SDL_Renderer* renderer){
    rk.setHp(2000);
    rk.setSpeed(3);
    rk.changeImageSize( 5,5);
    rk.x = 600 - rk.frame.w/2 ;
    rk.y =  750 - rk.frame.h ;
    rk.setXY(rk.x,rk.y); /// vi tri ban dau
    rk.update();
}
void initHp(object &hp, SDL_Renderer* renderer){
    string s = "./pictures//hp.png";
    hp.init(renderer, s);
    hp.changeImageSize(15,15);

}
void effect (SDL_Renderer* &renderer, const object &v){
    /// truyen toa do vao
    string s1 = "./pictures//effect1.png";
    object effect1 ;
    effect1.changeImageSize(4,4);
    effect1.init(renderer, s1);

    /// set toa do sao cho effect chinh giua bubble
    int x = v.frame.x + v.frame.w/2 - effect1.frame.w/2 ;
    int y = v.frame.y + v.frame.h/2 - effect1.frame.h/2;


    effect1.setXY(x,y);
    effect1.update();
}

void dropEgg(int real_imp_time,vector <chicken> &v,vector<egg>&eggs){
    if(v.size()!=0){
                for(int j = 0; j < 5; j++){
                    int i = rand()%v.size();
                    if(real_imp_time % (600+50*i) == 0 && real_imp_time > 10 ){

                        eggs[i].frame.x = v[i].frame.x + v[i].frame.w/2 - eggs[i].frame.w/2 ;
                        eggs[i].frame.y = v[i].frame.y + v[i].frame.y/2 - eggs[i].frame.h/2 ;

                    }
                }
        }

        for(int i =0; i < eggs.size(); i++){
            if(eggs[i].frame.y < 653){
                eggs[i].falling();
            }
            else{
                eggs[i].setXY(1000,1000); /// de no khong hien thi duoc nua
                /// va cai rk cung khong cham vao duoc
            }
        }
}
void flying(SDL_Renderer *renderer, bool& toRight,vector <chicken> &v1, vector<chicken>&v2){
    for(int i = 0; i <v1.size(); i++){
            v1[i].floating(toRight);
            ///v[i].animation(path);
            v1[i].update();
        }
    for(int i = 0; i < v2.size(); i++){
        v2[i].floating2(toRight);
        v2[i].update();
    }

}
void handleEvent(SDL_Event g_event,float& deltaX,float& deltaY, int &temp){
    if(SDL_PollEvent(&g_event)){

                switch(g_event.type){
                case SDL_KEYDOWN:{
                    switch(g_event.key.keysym.sym ){
                        case SDLK_UP:{ /// di len thi y giam

                            deltaX = 0 ;
                            deltaY = -1 ;
                            break ;
                        }
                        case SDLK_DOWN:{/// di xuong thi y tang
                            deltaX = 0 ;
                            deltaY = 1 ;
                            break ;
                        }
                        case SDLK_LEFT:{/// di sang trai thi x giam
                            deltaX = -1 ;
                            deltaY = 0 ;
                            break;
                        }
                        case SDLK_RIGHT:{/// di sang phai thi x tang
                            deltaX = 1 ;
                            deltaY = 0 ;
                            break ;
                        }
                        case SDLK_SPACE:{ /// ban ra tia
                            temp = 1;

                        break ;
                        }

                    }

                }
            }
        }
}
void  ThunderAndChicken(int &temp,object obj[],vector <drumStick> &drs,vector <vector<chicken>> &chickens,SDL_Renderer* &renderer,drumStick ds ){
    /// between thunder and chicken
    if(temp == 1){

                int a = obj[1].frame.x + (obj[1].frame.w-obj[2].frame.w)/2;
                int b = obj[1].frame.y - obj[2].frame.h+2;
                obj[2].setXY(a,b);
                obj[2].update();
                    for(int k = 0; k <=1 ; k++){
                        for(int i = 0; i <chickens[k].size(); i++){

                            if(SDL_HasIntersection(&obj[2].frame,&chickens[k][i].frame)){
                            /// va cham giua thunder va chicken
                            ///effect
                            effect(renderer, chickens[k][i]);
                            int x1 =chickens[k][i].frame.x + chickens[k][i].frame.w/2 -ds.frame.w/2;
                            int y1 =chickens[k][i].frame.y + chickens[k][i].frame.h/2 -ds.frame.h/2;
                            ds.setXY(x1, y1);
                            drs.push_back(ds);
                            chickens[k].erase(chickens[k].begin()+i);
                            i--;
                            }
                        }
                    temp = 0;
                    }

    }
}
void drumstickAndSpaceship(vector <drumStick> &drs, object &spaceship, int &mark){
     for(int i = 0; i < drs.size(); i++){

                if(drs[i].frame.y < 690){
                    drs[i].frame.y += drs[i].speed ;
                    drs[i].update();
                    if(SDL_HasIntersection(&spaceship.frame,&drs[i].frame)){
                        drs.erase(drs.begin()+i);
                        mark+=10;
                        cout << mark<<endl;
                    }
                }
                else{
                    /// nay dung ma nhi
                    drs.erase(drs.begin() + i);
                    i--;
                }

        }

}
void hpRender(vector<egg> &eggs, vector <object> &hps, object &spaceship){

    for(int i = 0; i < eggs.size(); i++){
            if(SDL_HasIntersection(&spaceship.frame,&eggs[i].frame)){
                eggs[i].setXY(1000,1000);
                if(hps.size()==0){
                    return ;
                }
                else{
                    hps.erase(hps.begin());

                }
            }
    }

    for(int i = 0; i < hps.size(); i++){
                hps[i].update();
    }

}
void showTime(const int &real_imp_time, textObject &time_game,SDL_Renderer* &renderer,TTF_Font* font_time ){
        string str_time = "Time: ";
        Uint32 time_val = real_imp_time/1000;
        Uint32 val_time = 120 - time_val ;
        if(val_time <= 0){
            SDL_Quit();
        }
        else{
            string str_val = to_string(val_time);
            str_time += str_val;
            time_game.SetText(str_time);
            time_game.LoadFromRenderText(font_time, renderer);
            time_game.RenderText(renderer, 500,15, nullptr, 0.0, nullptr, SDL_FLIP_NONE);
        }

}
void showScore(const int& score, textObject &score_text, SDL_Renderer* &renderer, TTF_Font* font_time){
        string str_score ="Score: ";
        Uint32 score_ = score ;
        string score_val = to_string(score_);
        str_score += score_val ;
        score_text.SetText(str_score);
        score_text.LoadFromRenderText(font_time, renderer);
        score_text.RenderText(renderer, 0,15, nullptr, 0.0, nullptr, SDL_FLIP_NONE);

        ///cout <<"your score : "<<score<<endl ;

}

void handle(object obj[],
             vector <vector<chicken>> chickens,
             SDL_Renderer* renderer,
             SDL_Event g_event, vector<egg> &eggs,
             egg&opla,
             textObject time_game,
             TTF_Font* font_time,
             textObject score_text)
{
    vector <int> highScore ;
    float deltaX, deltaY ;
    int temp = 0;
    bool toRight = true ;
    bool toRight2 = true ;
    /// init ds
    drumStick ds;
    initDrumStick(ds, renderer);
    /// set up timer
    ImpTimer fps_timer;
    fps_timer.start();
    /// init hp
    object hp;
    initHp(hp, renderer);
    vector <object> hps ;
    for(int i = 0; i < 5; i++){
        hp.setXY(980+hp.frame.w*i,10);
        hps.push_back(hp);
    }
    int real_imp_time ;
    int score = 0;
    ///textObject time_game;
    ///textObject score_text;

    vector <drumStick> drs ;

    while(true){
        real_imp_time = fps_timer.get_ticks();

        flying(renderer,toRight,chickens[0],chickens[1]);

        dropEgg(real_imp_time, chickens[0], eggs);

        dropEgg(real_imp_time, chickens[1], eggs);

        handleEvent(g_event, deltaX,deltaY,temp);

        obj[1].changeXY(deltaX, deltaY);

        if(obj[0].frame.y+obj[0].frame.h >= 750  && obj[3].frame.y <= 0){
            obj[0].frame.y -= deltaY*obj[1].speed ; /// bg1
            obj[3].frame.y -= deltaY*obj[1].speed ; /// bg2
        }

        ThunderAndChicken(temp,obj,drs,chickens,renderer,ds );

        drumstickAndSpaceship(drs, obj[1], score);

        hpRender(eggs,hps,obj[1]);

        showScore(score, score_text, renderer,font_time);

        showTime(real_imp_time, time_game, renderer, font_time);

        obj[1].update();
        Present(renderer);
        obj[0].update();
        obj[3].update();

    }

}
void play(){
        SDL_Window* window = NULL ;
        SDL_Renderer* renderer = NULL;
        initSDL(window, renderer);
        bool success ;
        if(TTF_Init()==-1){
            cout <<"khong thanh cong"<<endl;
            success = false ;
        }
        TTF_Font* font_time = nullptr;
        font_time = TTF_OpenFont("font//font2.ttf", 40);
        if(font_time == NULL){
            success = false ;
        }
        textObject time_game ;
        textObject score_text;

        ///time_game.SetColor(255,255,255);







        ///initbg
        object bg;
        string s1 = "./pictures//bg1.png";
        bg.init(renderer,s1);
        bg.frame = {0,0,1200,750};
        bg.update();
        switch(Menu(renderer)){
            case 0 : // play y
                break ;
            case 1:

               break;
            case 2:
                return ; /// gap exit thi thoat luon thoi
                break ;
        }
        ///initbg2
        object bg2 ;
        string s0 = "./pictures//bg2.png";
        bg2.init(renderer, s0);
        //int h = SCREEN_HEIGHT;
        bg2.frame = {0,-750, 1200, 750};
        ///init rocket
        object rk;
        string s2 = "./pictures//spaceship0.png";
        rk.init(renderer,s2);
        initRocket(rk, renderer);


        ///init thunder
        object thunder;
        string s3 = "./pictures//thunder.png";
        thunder.init(renderer, s3);
        thunder.changeImageSize(0.16,9);

        ///init chicken
        string s4 ="./pictures//chicken007.png";
        chicken bubble;
        bubble.init(renderer, s4);
        bubble.changeImageSize(5,5);
        vector <chicken> v;
        vector <vector<chicken>> vv ;
        /// hay lai tao 1 cai mang nua nhi
        for(int i = 0; i < 10; i++){
            bubble.setXY(20+ (bubble.frame.w+10)*(i+1), 100+20*i);
            v.push_back(bubble);
        }
        /// init chicken2
        string s9 ="./pictures//chicken008.png";
        chicken ck2;
        ck2.init(renderer, s9);
        ck2.changeImageSize(7,7);
        vector<chicken> v2 ;
        for(int i = 0; i <10; i++){
            ck2.setXY(20+ (ck2.frame.w+10)*(i+1), 100+20*i);
            v2.push_back(ck2);
        }
        for(int i = 0; i < 20; i++){
            if(i % 2 ==0 ){
                vv.push_back(v);
            }
            else{
                vv.push_back(v2);
            }

        }

        ///init egg
        egg e ;
        string s5 = "./pictures//egg.png";
        vector <egg> eggs ;
        for(int i = 0; i < 10; i++){
            e.init(renderer, s5);
            e.changeImageSize(18,18);
            e.setXY(100,100);
            eggs.push_back(e);
        }
        ///init opla
        object character[4]={bg, rk, thunder,bg2};
        string s6 = "./pictures//opla.png";
        egg opla ;
        opla.init(renderer, s6);
        opla.changeImageSize(17,17);
        opla.setXY(100,100);
        ///handle
        SDL_Event g_event ;
        handle(character,vv, renderer, g_event, eggs, opla, time_game,font_time,score_text);

        return ;
}
