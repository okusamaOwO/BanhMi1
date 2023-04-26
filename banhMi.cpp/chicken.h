#ifndef CHICKEN__H_
#define CHICKEN__H_
#include"class.h"
#include"egg.h"
class chicken:public object{
public:
    bool isAlive;
    void floating(bool &toRight);
    void dropEgg(egg &e, egg &opla);
    void floating2(bool &toRight);
};

#endif // CHICKEN__H_


