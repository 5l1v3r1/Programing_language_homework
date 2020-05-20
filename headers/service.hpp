#ifndef SERVÝCE_H
#define SERVÝCE_H
#include "busy.hpp"
class Service{
   private:
        string courseCode;

    public:
        vector<string> serviceDays;
        Service(string courseCode,vector<string> serviceDays){
            this->courseCode=courseCode;
            this->serviceDays=serviceDays;
        };
        ~Service(){};
        string getCourseCode(){
            return courseCode;
        }
};

#endif
