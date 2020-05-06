#include <iostream>
#include <string>
#include <vector>
#include "headers/compulsoryCourse.hpp"
using namespace std;


int main(){

    vector<CompulsoryCourse> compulsoryCourse;
    CompulsoryCourse cc("asdasd","asdsad","adsads",5,10);
    compulsoryCourse.push_back(cc);

    //vector<CompulsoryCourse>::iterator it;

    for(int i = 0; i<compulsoryCourse.size();i++){
        cout<<compulsoryCourse[i].getType() << endl;
    }


    return 0;
}

