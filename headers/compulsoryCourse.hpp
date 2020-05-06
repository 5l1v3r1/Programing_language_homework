#include <string>
#include "course.hpp"
using namespace std;
class CompulsoryCourse:public Course
{
    private:
        string type;
    public:
        CompulsoryCourse(string courseCode,string courseName,string instructorName,int grade,int credit,string type="C"):Course(courseCode,courseName,instructorName,grade,credit){
            this-> type = type;
        };
        string getType(){
            return this -> type;
        }

};

