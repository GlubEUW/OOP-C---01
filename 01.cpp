#include <iostream>
#include <sstream>

using namespace std;

class Animal{
    Animal(){
            status = true;
        }

    private:
        string name;
        int age, legCount;
        bool status;

    public:

        void setName(string n){name = n;}
        string getName(){return name;}

        void setAge(int a){age = a;}
        int getAge(){return age;}

        void setLegCount(int l){legCount = l;}
        int getLegCount(){return legCount;}

        bool isDead(){return status;}
        void dead(){status = 0;}
        void alive(){status = 1;}
        string toString(){
            stringstream ss;
            ss << name << " "<< age << " " << legCount << " " << status;
            return ss.str();
        }
};

int main(){

}
