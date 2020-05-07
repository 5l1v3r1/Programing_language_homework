#ifndef ELECTÝVECOURSE_H
#define ELECTÝVECOURSE_H

#include <string>
#include "course.hpp"
class ElectiveCourse:public Course{
    private:
        string type;
    public:
        ElectiveCourse(string courseCode,string courseName,int grade,int credit,string typeOfCourse,string instructorName,string type="E"):Course(courseCode,courseName,grade,credit,instructorName,typeOfCourse){
            this-> type = type;
        };
        string getType(){
            return this -> type;
        }
};
#endif
