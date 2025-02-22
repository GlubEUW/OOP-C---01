#include <iostream>
#include <sstream>

using namespace std;

class Animal{


    private:
        string name;
        int age, legCount;
        bool status;

    public:
        Animal(string n, int a, int l){
            name = n;
            age = a;
            legCount = l;
            status = true;
        }
        Animal(int a, int l){
            age = a;
            legCount = l;
            status = true;
        }

        void setName(string n){name = n;}
        string getName(){return name;}

        void setAge(int a){
            try{
                if(age>=0)
                    age = a;
                else
                    throw (age);
            }
            catch (int age){
            cout << "Age must be positive" << endl;
            }
        }
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

    Animal cow(12,4);

    cout << cow.toString() << endl;


    return 0;
}
