#ifndef CLASSROOMSTATE_H
#define CLASSROOMSTATE_H
class ClassRoomState{
    private:

    public:

        string day,time;
        int bigClassRoom,smallClassRoom;
        vector<string> big,small;

        ClassRoomState(int bigClassRoom,int smallClassRoom){
            this ->bigClassRoom=bigClassRoom;
            this->smallClassRoom=smallClassRoom;

        }
        ClassRoomState(string day,string time,int bigClassRoom,int smallClassRoom){
            this ->day=day;
            this ->time = time;
            this ->bigClassRoom=bigClassRoom;
            this ->smallClassRoom=smallClassRoom;
            this ->big = giveBigClassName(bigClassRoom);
            this ->small = giveSmallName(smallClassRoom);
        }
        ClassRoomState(string day,string time){
            this -> day = day;
            this -> time = time;
        }

        vector<ClassRoomState> getClassRoomState(){
            vector<ClassRoomState> classRoomState;
            classRoomState.push_back(ClassRoomState("Monday","Morning",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Monday","Afternoon",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Tuesday","Morning",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Tuesday","Afternoon",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Wednesday","Morning",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Wednesday","Afternoon",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Thursday","Morning",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Thursday","Afternoon",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Friday","Morning",bigClassRoom,smallClassRoom));
            classRoomState.push_back(ClassRoomState("Friday","Afternoon",bigClassRoom,smallClassRoom));
            return classRoomState;
        }

        vector<string> giveBigClassName(int bigCout){
            vector<string> bigClassName;
            string name;
            for(int i = 0; i<bigCout;i++){
                name = "bigclass" + to_string(i);
                bigClassName.push_back(name);
            }
            return bigClassName;
        }

        vector<string> giveSmallName(int smallCount){
            vector<string> smallClassName;
            string name;
            for(int i = 0; i<smallCount;i++){
                name = "smallclass" +to_string(i);
                smallClassName.push_back(name);
            }
            return smallClassName;
        }

        void changeBigClassRoom(bool isIncrease){
            if(isIncrease){
                bigClassRoom++;
            }
            else if(bigClassRoom != 0 ){
                bigClassRoom--;
            }
            else{
                string noClass = "You don't have any classroom, you should increase the class number";
                throw noClass;
            }
        }


        void changeSmallClassRoom(bool isIncrease){
            if(isIncrease){
                smallClassRoom++;
            }
            else if(bigClassRoom != 0 ){
                smallClassRoom--;
            }
            else{
                string noClass = "You don't have any classroom, you should increase the class number";
                throw noClass;
            }
        }

        friend bool operator==(const ClassRoomState &obj1,const ClassRoomState &obj2){
            if(obj1.day == obj2.day && obj1.time==obj2.time){
                return true;
            }
            else{
                return false;
            }
        }


};
#endif // CLASSROOMSTATE_H
