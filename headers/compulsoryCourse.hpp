#ifndef COMPULSORYCOURSE_H
#define COMPULSORYCOURSE_H

#include <string>
#include "course.hpp"

class CompulsoryCourse:public Course
{
    private:
        string type;
    public:
        CompulsoryCourse(string courseCode,string courseName,int grade,int credit,string typeOfCourse,string instructorName, string type="C"):Course(courseCode,courseName,grade,credit,instructorName,typeOfCourse)
        {
            this-> type = type;
        };
        CompulsoryCourse(string courseCode,string type="C"):Course(courseCode)
        {
            this->type=type;
        }
        ~CompulsoryCourse() {};
        string getType()
        {
            return this -> type;
        }
        string getCourseCode()
        {
            return this->courseCode;
        }

        friend bool operator==(const CompulsoryCourse &obj1,const CompulsoryCourse &obj2)
        {
            if(obj1.courseCode==obj2.courseCode)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

#endif
