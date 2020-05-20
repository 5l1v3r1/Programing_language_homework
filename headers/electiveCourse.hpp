#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include <string>
#include "course.hpp"
class ElectiveCourse:public Course{
    private:
        string type;
    public:
        ElectiveCourse(string courseCode,string courseName,int grade,int credit,string typeOfCourse,string instructorName,string type="E"):Course(courseCode,courseName,grade,credit,instructorName,typeOfCourse){
            this-> type = type;
        };
        ElectiveCourse(string courseCode,string type="E"):Course(courseCode){
            this->type=type;
        }
        ~ElectiveCourse(){};
        string getType(){
            return this -> type;
        }

        friend bool operator==(const ElectiveCourse &obj1,const ElectiveCourse &obj2){
            if(obj1.courseCode == obj2.courseCode){
                return true;
            }
            else{
                return false;
            }
        }
};
#endif
