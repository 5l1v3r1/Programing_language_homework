#ifndef CLASSROOMSTATE_H
#define CLASSROOMSTATE_H
class ClassRoomState{
    private:

    public:

        string day;
        int bigClassRoom,smallClassRoom;

        ClassRoomState(int bigClassRoom,int smallClassRoom){
            this ->bigClassRoom=bigClassRoom;
            this->smallClassRoom=smallClassRoom;

        }
        ClassRoomState(string day,int bigClassRoom,int smallClassRoom){

            this ->bigClassRoom=bigClassRoom;
            this->smallClassRoom=smallClassRoom;

        }
        vector<ClassRoomState> getClassRoomState(){
            vector<ClassRoomState> classRoomState;
            classRoomState.push_back(ClassRoomState("Monday",this->bigClassRoom,this->smallClassRoom));
            classRoomState.push_back(ClassRoomState("Tuesday",this->bigClassRoom,this->smallClassRoom));
            classRoomState.push_back(ClassRoomState("Wednesday",this->bigClassRoom,this->smallClassRoom));
            classRoomState.push_back(ClassRoomState("Thursday",this->bigClassRoom,this->smallClassRoom));
            classRoomState.push_back(ClassRoomState("Friday",this->bigClassRoom,this->smallClassRoom));
        }
};
#endif // CLASSROOMSTATE_H
