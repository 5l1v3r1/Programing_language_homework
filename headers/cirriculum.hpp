#ifndef C�RR�CULUM_H
#define C�RR�CULUM_H
#include "classroom.hpp"
using namespace std;

class Cirriculum{
    private:
        enum days {Monday,Tuesday,Wednesday,Thursday,Friday};
        enum times {Morning,Afternoon};

    public:
        days day;
        times time;
        string courseCode;
        //classroom

        Cirriculum(string courseCode){
            this -> day = day;
        };

};
#endif  C�RR�CULUM_H
