#ifndef CLASSROOM_H
#define CLASSROOM_H
using namespace std;
class ClassRoom{
    private:
        int numberOfClass;
    public:
        ClassRoom(int numberOfClass){
            this -> numberOfClass = numberOfClass;
        }
        ~ClassRoom(){};

        int getNumberOfClass(){
            return this -> numberOfClass;
        };
        void setNumberOfClass(int classNumber){
            this -> numberOfClass = classNumber;
        }


};
#endif

