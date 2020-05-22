#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "cirriculum.hpp"
#include "busy.hpp"

using namespace std;
//template<class T>
class Scheduler
{
    private:
        vector<Cirriculum> cirriculum;
        vector<string> ReadFile(string fileName)
        {
            string line;
            ifstream file (fileName);
            vector<string> words;
            //read file
            if(file.is_open())
            {
                //split by ';'
                while(getline(file,line,';'))
                {
                    stringstream linestream(line);
                    string value;
                    //separate word by word
                    while(getline(linestream,value))
                    {
                        words.push_back(value);
                    }
                }
            }
            file.close();
            return words;
        }
        bool iequals(const string& a, const string& b)
        {
            return equal(a.begin(), a.end(),
                         b.begin(), b.end(),
                         [](char a, char b)
            {
                return tolower(a) == tolower(b);
            });
        }
    public:
        Scheduler() {};
        ~Scheduler() {};
        template<class T,class N>
        void Courses(string fileName,vector<T> *v,vector<N> *n)
        {
            vector<string> words = ReadFile(fileName);
            /*Check type of object*/
            if((typeid(T)== typeid(CompulsoryCourse) && (typeid(N)==typeid(ElectiveCourse))))
            {
                for(int i = 0; i<words.size(); i+=7)
                {
                    if(words[i+4] == "C")
                    {
                        v->push_back(T(words[i],words[i+1],stoi(words[i+2]),stoi(words[i+3]),words[i+5],words[i+6]));
                    }
                    else if(words[i+4] == "E")
                    {
                        n->push_back(N(words[i],words[i+1],stoi(words[i+2]),stoi(words[i+3]),words[i+5],words[i+6]));
                    }
                }
            }
        }
        template<class T,class N>
        void ClassRoom(string fileName,vector<T> *v,vector<N> *n)
        {
            vector<string> words = ReadFile(fileName);
            if((typeid(T)== typeid(BigClassRoom) && (typeid(N)==typeid(SmallClassRoom))))
            {
                for(int i = 0; i<words.size(); i+=2)
                {
                    if(iequals(words[i],"bigclass"))
                    {
                        v->push_back(T(stoi(words[i+1])));
                    }
                    else if(iequals(words[i],"smallclass"))
                    {
                        n->push_back(N(stoi(words[i+1])));

                    }
                }
            }
        }

        template<class T>
        void BusyFile(string fileName,vector<T> *v)
        {
            vector<string> words = ReadFile(fileName);
            /*if(typeid(T)==typeid(Busy)){

            } */
            for(int i =0; i<words.size(); i+=3)
            {
                v->push_back(T(words[i],vector<string> {words[i+1],words[i+2]}));
            }
        }

        template<class T>
        void Service(string fileName,vector<T> *v)
        {

            vector<string> words = ReadFile(fileName);

            for(int i=0; i<words.size(); i+=3)
            {

                v->push_back(T(words[i],vector<string> {words[i+1],words[i+2]}));
            }
        }

        vector<Cirriculum> getCirriculum(){
            return this->cirriculum;
        }


};

