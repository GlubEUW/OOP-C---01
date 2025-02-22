#include <iostream>
#include <sstream>

using namespace std;

class Animal{

    string name;
    int age, legCount;
    bool status;

    string toString(){
        stringstream ss;
        ss << name << " "<< age << " " << legCount << " " << status;
        return ss.str();
    }
};

int main(){




}
