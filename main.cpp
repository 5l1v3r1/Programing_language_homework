#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "headers/cirriculum.hpp"
#include "headers/compulsoryCourse.hpp"
#include "headers/electiveCourse.hpp"
#include "headers/smallClassroom.hpp"
#include "headers/bigClassroom.hpp"
#include "headers/scheduler.hpp"
#include "headers/busy.hpp"
#include "headers/service.hpp"

using namespace std;

void isEnough(int numberOfClass,int numberOfCourse){
    if(!(numberOfClass*5*2>=numberOfCourse)){
        bool isEnough = false;
        throw isEnough;
    }
}

void serviceCourse(vector<Service> *service,vector<CompulsoryCourse> *compulsoryCourse,vector<ElectiveCourse> *electiveCourse,vector<Cirriculum> *cirriCulum){
    vector<CompulsoryCourse>::iterator it;
    vector<ElectiveCourse>::iterator it2;
    for(int i=0; i<service->size();i++){
        string courseCode=service->at(i).getCourseCode();
        it = find(compulsoryCourse->begin(),compulsoryCourse->end(),CompulsoryCourse(courseCode));
        it2 = find(electiveCourse->begin(),electiveCourse->end(),ElectiveCourse(courseCode));
        if(it != compulsoryCourse->end()){
            int courseIndex = distance(compulsoryCourse->begin(),it);
            Cirriculum cirriCulum(courseCode,compulsoryCourse->at(courseIndex).grade,"C",service->at(i).serviceDays[0],service->at(i).serviceDays[1]);
            cout<<cirriCulum.day<<"\n";
        }
        else if(it2 != electiveCourse->end()){
            int courseIndex = distance(electiveCourse->begin(),it2);
            Cirriculum cirriCulum(courseCode,compulsoryCourse->at(courseIndex).grade,"C",service->at(i).serviceDays[0],service->at(i).serviceDays[1]);
            cout<<cirriCulum.day<<"\n";
        }
        else{
            string cantFind = "Can not find course code, you should check your file";
            throw cantFind;
        }
    }



}


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
    vector<Cirriculum> cirriCulum = scheduler.getCirriculum();

    try{
        //isEnough((bigClassRoom[0].getNumberOfClass()+smallClassRoom[0].getNumberOfClass()),cirriCulum.size());
        serviceCourse(&service,&compulsoryCourse,&electiveCourse,&cirriCulum);
    }
    catch(bool isEnough){
        cout << "Classrooms is not enough, you should increase the class number";

    }
    catch(string convertError){
        cout<<convertError;
    }
    catch(string cantFind){
        cout<<cantFind;
    }
    catch(...){
        cout << "Unknown Error";
    }

    return 0;
};

