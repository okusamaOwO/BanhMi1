#include"drumStick.h"
coordinate drumStick::center (chicken ck){
    coordinate a ;
    frame.x = ck.frame.x + ck.frame.w/2 -frame.w/2;
    frame.y = ck.frame.y + ck.frame.h/2 -frame.h/2;
    return a ;
}
void drumStick:: fallingOut(chicken &ck){
    /// parabol huong xuong
    frame.x = sqrt(frame.y);
}
bool drumStick::onTheGround(){
    if(frame.y > 700){
        return true ;

    }
    return false ;

}
