#ifndef SMALLCLASSROOM_H
#define SMALLCLASSROOM_H
#include "classroom.hpp"


class SmallClassRoom:public ClassRoom{
    public:
        SmallClassRoom(int numberOfClass):ClassRoom(numberOfClass){};
};
#endif
