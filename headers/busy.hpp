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
        Busy(string courseCode){
            this->courseCode=courseCode;
        }
        ~Busy(){};
        string getCourseCode(){
            return courseCode;
        }

        friend bool operator==(const Busy &obj1,const Busy &obj2){
            if(obj1.courseCode == obj2.courseCode){
                return true;
            }
            else{
                return false;
            }
        }


};
#endif // BUSY_H
