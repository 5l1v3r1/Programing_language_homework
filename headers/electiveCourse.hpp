#include <string>
#include "course.hpp"
class ElectiveCourse:public Course{
    private:
        string type;
    public:
        ElectiveCourse(string courseCode,string courseName,string instructorName,int grade,int credit,string type="E"):Course(courseCode,courseName,instructorName,grade,credit){
            this-> type = type;
        };
        string getType(){
            return this -> type;
        }
};
