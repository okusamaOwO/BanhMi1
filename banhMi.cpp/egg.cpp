#include"egg.h"
void egg::falling(){
    if(frame.y <= 650){
        frame.y += 7;
        update();
    }
}

