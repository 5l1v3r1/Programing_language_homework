#ifndef CİRRİCULUM_H
#define CİRRİCULUM_H
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
#endif  CİRRİCULUM_H
