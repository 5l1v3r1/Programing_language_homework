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
#include "headers/classroomState.hpp"

using namespace std;

void isEnough(int numberOfClass,int numberOfCourse){
    if(!(numberOfClass*5*2>=numberOfCourse)){
        bool isEnough = false;
        throw isEnough;
    }
}


int checkDate(vector<ClassRoomState> classRoomState,bool isBigClass,Busy *busy = nullptr){
    int count = 0;
    int index = -1;
    if(busy == nullptr){
        if(isBigClass){
            while(index==-1){
                if(classRoomState[count].bigClassRoom > 0){
                    index = count;
                }
                count++;
            }
        }
        else{
              while(index==-1){
                if(classRoomState[count].smallClassRoom > 0 ||classRoomState[count].bigClassRoom > 0){
                    index = count;
                }
                count++;
            }
        }
    }
    else{
        if(isBigClass){
              while(index==-1){
                 if(classRoomState[count].day != busy->busyDays[0] && classRoomState[count].time != busy->busyDays[1]){                    if(classRoomState[count].bigClassRoom > 0 ){
                        index = count;
                    }
                }
                count++;
            }
        }
        else{
              while(index==-1){
                if(classRoomState[count].day != busy->busyDays[0] && classRoomState[count].time != busy->busyDays[1]){                   if(classRoomState[count].smallClassRoom > 0 || classRoomState[count].bigClassRoom > 0 ){
                        index = count;
                    }
                }
                count++;
            }
        }
    }

    return index;
}

void serviceCourse(vector<Service> *service,vector<CompulsoryCourse> *compulsoryCourse,vector<ElectiveCourse> *electiveCourse,vector<Cirriculum> *cirriCulum,vector<ClassRoomState> *classRoomState){
    vector<CompulsoryCourse>::iterator it;
    vector<ElectiveCourse>::iterator it2;
    vector<ClassRoomState>::iterator it3;
    for(int i=0; i<service->size();i++){
        string courseCode=service->at(i).getCourseCode();
        string day= service->at(i).serviceDays[0];
        string time = service->at(i).serviceDays[1];
        it = find(compulsoryCourse->begin(),compulsoryCourse->end(),CompulsoryCourse(courseCode));
        it2 = find(electiveCourse->begin(),electiveCourse->end(),ElectiveCourse(courseCode));
        it3 = find(classRoomState->begin(),classRoomState->end(),ClassRoomState(day,time));
        if(it != compulsoryCourse->end()){
            int courseIndex = distance(compulsoryCourse->begin(),it);
            int classIndex = distance(classRoomState->begin(),it3);
            cirriCulum->push_back(Cirriculum(courseCode,compulsoryCourse->at(courseIndex).grade,"C",day,time,"bigclass"));
            classRoomState->at(classIndex).changeBigClassRoom(false);
            compulsoryCourse->erase(compulsoryCourse->begin()+courseIndex);
        }
        else if(it2 != electiveCourse->end()){
            int courseIndex = distance(electiveCourse->begin(),it2);
            int classIndex = distance(classRoomState->begin(),it3);
            classRoomState->at(classIndex).changeSmallClassRoom(false);
            cirriCulum->push_back(Cirriculum(courseCode,compulsoryCourse->at(courseIndex).grade,"C",day,time,"smallclass"));
            electiveCourse->erase(electiveCourse->begin()+courseIndex);
        }
        else{
            string cantFind = "Can not find course code, you should check your file";
            throw cantFind;
        }
    }
}

int checkBusyTimes(vector<Busy> busy,string courseCode){
    vector<Busy>::iterator it;
    it = find(busy.begin(),busy.end(),Busy(courseCode));
    if(it!=busy.end()){
        return distance(busy.begin(),it);
    }
    else{
        return -1;
    }
}

void compulsorySchedule(vector<CompulsoryCourse> *compulsoryCourse,vector<ClassRoomState> *classRoomState,vector<Cirriculum> *cirriCulum,vector<Busy> *busy){
    string day,time;
    for(int i=0; i<compulsoryCourse->size();i++){
        int checkBusy = checkBusyTimes(*busy,compulsoryCourse->at(i).courseCode);
        int classIndex;
        if(checkBusy!=-1){
            classIndex = checkDate(*classRoomState,true,&busy->at(checkBusy));
            day = classRoomState->at(classIndex).day;
            time = classRoomState->at(classIndex).time;
            cirriCulum->push_back(Cirriculum(compulsoryCourse->at(i).courseCode,compulsoryCourse->at(i).grade,"C",day,time,"bigclass"));
            classRoomState->at(classIndex).changeBigClassRoom(false);
            cout<<classIndex<<"\n";
        }
        else{
            classIndex = checkDate(*classRoomState,true);
            day = classRoomState->at(classIndex).day;
            time = classRoomState->at(classIndex).time;
            cirriCulum->push_back(Cirriculum(compulsoryCourse->at(i).courseCode,compulsoryCourse->at(i).grade,"C",day,time,"bigclass"));
            classRoomState->at(classIndex).changeBigClassRoom(false);
            cout<<classIndex<<"\n";
        }
    }
}

void electiveSchedule(vector<ElectiveCourse> *electiveCourse,vector<ClassRoomState> *classRoomState,vector<Cirriculum> *cirriCulum, vector<Busy> *busy){
   string day,time;
   for(int i=0; i<electiveCourse->size();i++){
        int checkBusy = checkBusyTimes(*busy,electiveCourse->at(i).courseCode);
        int classIndex;
        if(checkBusy!=-1){
            classIndex = checkDate(*classRoomState,false,&busy->at(checkBusy));
            day = classRoomState->at(classIndex).day;
            time = classRoomState->at(classIndex).time;
            cirriCulum->push_back(Cirriculum(electiveCourse->at(i).courseCode,electiveCourse->at(i).grade,"C",day,time,"smallclass"));
            //classRoomState->at(classIndex).changeSmallClassRoom(false);
            cout<<classIndex<<"\n";
        }
        else{
            classIndex = checkDate(*classRoomState,true);
            day = classRoomState->at(classIndex).day;
            time = classRoomState->at(classIndex).time;
            cirriCulum->push_back(Cirriculum(electiveCourse->at(i).courseCode,electiveCourse->at(i).grade,"C",day,time,"smallclass"));
            //classRoomState->at(classIndex).changeSmallClassRoom(false);
            cout<<classIndex<<"\n";
        }
    }
}

void checkGrade(){

}


void test(vector<CompulsoryCourse> compulsoryCourse,vector<ElectiveCourse> electiveCourse,vector<BigClassRoom> bigClassRoom,vector<SmallClassRoom> smallClassRoom,vector<Busy> busy,vector<Service> service,vector<Cirriculum> cirriCulum){
       /*cout<<"Compulsory Courses"<<endl;
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
            cout<<"\n\n";
        }*/

        cout<<"Service Course Time"<<endl;
        for(int i=0;i<cirriCulum.size();i++){
            cout<<cirriCulum[i].courseCode + " "<<cirriCulum[i].grade + " "<<cirriCulum[i].day + " "<<cirriCulum[i].time+ " "<<cirriCulum[i].room<<endl;
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
    ClassRoomState classRoomState(bigClassRoom[0].getNumberOfClass(),smallClassRoom[0].getNumberOfClass());
    vector<Cirriculum> cirriCulum = scheduler.getCirriculum();
    vector<ClassRoomState> classState = classRoomState.getClassRoomState();
    try{
        cout<<classState[0].big[0];
        //isEnough((bigClassRoom[0].getNumberOfClass()+smallClassRoom[0].getNumberOfClass()),cirriCulum.size());
        /*serviceCourse(&service,&compulsoryCourse,&electiveCourse,&cirriCulum,&classState);
        compulsorySchedule(&compulsoryCourse,&classState,&cirriCulum,&busy);
        electiveSchedule(&electiveCourse,&classState,&cirriCulum,&busy);
        test(compulsoryCourse,electiveCourse,bigClassRoom,smallClassRoom,busy,service,cirriCulum);*/

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
    catch(string noClass){
        cout<<noClass;
    }
    catch(...){
        cout << "Unknown Error";
    }

    return 0;
};

