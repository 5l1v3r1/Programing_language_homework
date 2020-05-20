#include <iostream>
#include <string>
#include <vector>
#include "headers/cirriculum.hpp"
#include "headers/compulsoryCourse.hpp"
#include "headers/electiveCourse.hpp"
#include "headers/smallClassroom.hpp"
#include "headers/bigClassroom.hpp"
#include "headers/scheduler.hpp"
#include "headers/busy.hpp"
#include "headers/service.hpp"

using namespace std;



void test(vector<CompulsoryCourse> compulsoryCourse,vector<ElectiveCourse> electiveCourse,vector<BigClassRoom> bigClassRoom,vector<SmallClassRoom> smallClassRoom,vector<Busy> busy,vector<Service> service){
        cout<<"Compulsory Courses"<<endl;
        for(int i = 0; i<compulsoryCourse.size();i++){
        cout<<compulsoryCourse[i].courseCode + " " << compulsoryCourse[i].courseName + " " << compulsoryCourse[i].grade <<" "<<compulsoryCourse[i].credit << " " << compulsoryCourse[i].typeOfCourse + " " << compulsoryCourse[i].instructorName << endl;
        }

        cout<<"\nElective Courses"<<endl;
        for(int i = 0; i <electiveCourse.size();i++){
             cout<<electiveCourse[i].courseCode + " " << electiveCourse[i].courseName + " " << electiveCourse[i].grade <<" "<<electiveCourse[i].credit << " " << electiveCourse[i].typeOfCourse + " " << electiveCourse[i].instructorName << endl;

        }

        cout<<"\nBig Class Room"<<endl;
        for(int i =0; i<bigClassRoom.size();i++){
            cout << bigClassRoom[i].getNumberOfClass()<<endl;
        }
        cout<<"\nSmall Class Room"<<endl;

        for(int i=0; i<smallClassRoom.size();i++){
            cout<< smallClassRoom[i].getNumberOfClass()<<endl;
        }

        cout<<"\nBusy Time"<<endl;
        for(int i=0;i<busy.size();i++){
            cout << busy[i].getCourseCode() + " ";
            for(int j=0;j<busy[i].busyDays.size();j++){
                cout<<busy[i].busyDays[j] + " ";
            }
            cout<<"\n";
        }

        cout<<"\nService Time"<<endl;
        for(int i=0;i<service.size();i++){
            cout << service[i].getCourseCode() + " ";
            for(int j=0;j<service[i].serviceDays.size();j++){
                cout<<service[i].serviceDays[j] + " ";
            }
            cout<<"\n";
        }
    }

int main(){

    vector<CompulsoryCourse> compulsoryCourse;
    vector<ElectiveCourse> electiveCourse;
    vector<BigClassRoom> bigClassRoom;
    vector<SmallClassRoom> smallClassRoom;
    vector<Busy> busy;
    vector<Service> service;
    Scheduler scheduler;
    scheduler.Courses<CompulsoryCourse,ElectiveCourse>("courses.csv",&compulsoryCourse,&electiveCourse);
    scheduler.ClassRoom<BigClassRoom,SmallClassRoom>("classroom.csv",&bigClassRoom,&smallClassRoom);
    scheduler.BusyFile<Busy>("busy.csv",&busy);
    scheduler.Service("service.csv",&service);
    //test(compulsoryCourse,electiveCourse,bigClassRoom,smallClassRoom,busy,service);
    scheduler.tryCath();
    vector<Cirriculum> cirriCulum = scheduler.getCirriculum();
    cout<<cirriCulum.size();



    return 0;
};

