#ifndef
#define classroom

class ClassRoom{
    private:
        int numberOfClass;
    public:
        ClassRoom(int numberOfClass){
            this ->numberOfClass = numberOfClass;
        }

        int getNumberOfClass(){
            return this -> numberOfClass;
        };
        void setNumberOfClass(int classNumber){
            this.numberOfClass = classNumber;
        }


};
#endif
