#include"menu.h"
int Menu(SDL_Renderer* renderer){
    /// khoi tao menu
    string s ="./pictures//frameMenu.png";
    object frameMenu;
    frameMenu.init(renderer, s);
    frameMenu.changeImageSize(4,7);
    frameMenu.setXY(600-frameMenu.frame.w/2, 50);
    frameMenu.update();
    /// khoi tao cac phim
    string path[3] ={"./pictures//buttonPlay.png","./pictures//buttonOptions.png","./pictures//buttonExit2.png"};
    object button[3];
    button[0].init(renderer, path[0]);/// play
    button[1].init(renderer, path[1]);///options
    button[2].init(renderer, path[2]);///exit
    for(int i = 0; i < 3; i++){
        button[i].changeImageSize(20,2);
    }
    int x = 600 - button[0].frame.w/2 ;
    int y = 250;
    for(int i = 0; i < 3; i++){
        /// chi co y la thay doi, vi minh dang muon cai menu cua minh theo hinh doc ma
        button[i].setXY(x, y+2*button[0].frame.h*i/2);
        button[i].update() ;
    }
    Present(renderer);

    SDL_Event event ;
    bool menu = true ;
    while(menu == true){
        if(SDL_PollEvent(&event)){

            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:{ /// truong hop co phim an vao
                    int x = event.button.x ;
                    int y = event.button.y ;
                    for(int i = 0; i < 3; i++){
                        if((x >= button[i].frame.x && x <= button[i].frame.x + button[i].frame.w) /// neu ma no thuoc toa do 1 trong cac nut
                        && ( y >= button[i].frame.y && y <= button[i].frame.y + button[i].frame.h )){
                            button[i].vibrate();
                            /// nghi ik
                            if(i == 0 || i== 2 || i==1){
                                    menu = false ;
                                    return i ;
                            }
                            /// tai sao no ko ket thuc nhi

                        }


                    }

                }
            }


        }
    }
    return 1 ;
}
