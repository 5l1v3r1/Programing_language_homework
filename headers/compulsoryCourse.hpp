#ifndef COMPULSORYCOURSE_H
#define COMPULSORYCOURSE_H

#include <string>
#include "course.hpp"

class CompulsoryCourse:public Course
{
    private:
        string type;
    public:
        CompulsoryCourse(string courseCode,string courseName,int grade,int credit,string typeOfCourse,string instructorName, string type="C"):Course(courseCode,courseName,grade,credit,instructorName,typeOfCourse){
            this-> type = type;
        };
        string getType(){
            return this -> type;
        }
};

#endif
