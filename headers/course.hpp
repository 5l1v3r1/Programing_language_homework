#include <string>
using namespace std;
class Course{
    private:

    public:
        string courseCode,
        courseName,
        instructorName;
        int grade,credit;
        Course(string courseCode,string courseName,string instructorName,int grade,int credit){
            this->courseCode = courseCode;
            this->courseName = courseName;
            this->instructorName = instructorName;
            this->credit = credit;
            this->grade = grade;
    }
};

