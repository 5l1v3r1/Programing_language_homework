#ifndef CIRRICULUM_H
#define CIRRICULUM_H
#include "classroom.hpp"
#include "course.hpp"
using namespace std;

class Cirriculum:public Course
{
    private:
        enum days {Monday,Tuesday,Wednesday,Thursday,Friday};
        enum times {Morning,Afternoon};

    public:
        /*days day;
        times time;
        */
        string day,time;

        Cirriculum(string courseCode,int grade,string type):Course(courseCode,grade,type){

        };

        Cirriculum(string courseCode):Course(courseCode){};
        Cirriculum(string courseCode,int grade,string type,string day,string time):Course(courseCode,grade,type){
            /*this -> day = convertDays(day);
            this -> time= convertTimes(time);*/
            this -> day=day;
            this->time=time;
        };

        /*days convertDays(string &str){
            if(str=="Monday"){
                return Monday;
            }
            else if(str == "Tuesday"){
                return Tuesday;
            }
            else if(str == "Wednesday"){
                return Wednesday;
            }
            else if(str == "Thursday"){
                return Thursday;
            }
            else if(str == "Friday"){
                return Friday;
            }
            else{
                string convertError = "Can not convert string to enum";
                throw convertError;
            }
        }

        times convertTimes(string &str){
            if(str == "Morning"){
                return Morning;
            }
            else if(str == "Afternoon"){
                return Afternoon;
            }
            else{
                string convertError = "Can not convert string to enum";
                throw convertError;
            }
        }*/

        friend bool operator==(const Cirriculum &obj1, const Cirriculum &obj2){
            if(obj1.courseCode==obj2.courseCode){
                return true;
            }
            else{
                return false;
            }
        }

};
#endif  CIRRICULUM_H
