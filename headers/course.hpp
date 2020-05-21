#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;
class Course{
    private:

    public:
        string courseCode,
        courseName,
        instructorName,typeOfCourse;
        int grade,credit;
        Course(string courseCode,string courseName,int grade,int credit,string instructorName,string typeOfCourse){
            this->courseCode = courseCode;
            this->courseName = courseName;
            this->instructorName = instructorName;
            this->credit = credit;
            this->grade = grade;
            this->typeOfCourse=typeOfCourse;
        }

        Course(string courseCode){
            this -> courseCode = courseCode;
        }

        Course(string courseCode,int grade){
            this->courseCode=courseCode;
            this ->grade = grade;
        }
        Course(){};


        ~Course(){};
};
#endif
