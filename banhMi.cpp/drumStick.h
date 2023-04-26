#ifndef DRUMSTICK__H_
#define DRUMSTICK__H_
#include"class.h"
#include"chicken.h"
class drumStick : public object{
public:
    coordinate center(chicken &ck);
    void fallingOut(chicken ck);
    bool onTheGround();

};
#endif // DRUMSTICK__H_
