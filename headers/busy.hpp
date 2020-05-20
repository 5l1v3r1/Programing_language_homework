#ifndef BUSY_H
#define BUSY_H

class Busy{
    private:
        string courseCode;

    public:
        vector<string> busyDays;
        Busy(string courseCode,vector<string> busyDays){
            this->courseCode=courseCode;
            this->busyDays=busyDays;
        };
        ~Busy(){};
        string getCourseCode(){
            return courseCode;
        }


};
#endif // BUSY_H
