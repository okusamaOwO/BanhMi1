#include"chicken.h"
    void chicken::floating2(bool &toRight){
        if(toRight){
            frame.x+=1;
            //100*cos(listBoss[i].khung_nv.x*3.14/180) + 100
            frame.y = 50*sin(frame.x*3.14/180)+100;
            if(frame.x + frame.w >= 1200) toRight = false ;


        }
        else{
            frame.x-=1;
            frame.y = 50*sin(frame.x*3.14/180)+100;
            if(frame.x == 0) toRight = true;

        }

    }
    void chicken::floating(bool &toRight){
        if(toRight){
            frame.x+=1;
            //100*cos(listBoss[i].khung_nv.x*3.14/180) + 100
            frame.y = 50*cos(frame.x*3.14/180) + 50;
            if(frame.x + frame.w >= 1200) toRight = false ;


        }
        else{
            frame.x-=1;
            frame.y = 50*cos(frame.x*3.14/180) + 50;
            if(frame.x == 0) toRight = true;

        }
    }
    void chicken::dropEgg(egg &e, egg &opla){
        /// dropEgg nhu nao nhi
        if(e.frame.y <= 650){
        e.frame.y += 2 ;
        e.update();
        }

        if(e.frame.y >= 650){

            opla.setXY(e.frame.x, e.frame.y);
            ///cout << e.frame.x <<" "<<e.frame.y<<" "<<endl ;
            cout << opla.frame.x <<" "<<opla.frame.y<<endl ;
            opla.update();
        }

    }
