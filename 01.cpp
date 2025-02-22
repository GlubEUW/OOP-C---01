#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

class Animal{


    private:
        string name;
        int age, legCount;
        bool status;
        static int animalCount;
    public:
        Animal(string n, int a, int l){
            name = n;
            age = a;
            legCount = l;
            status = true;
            animalCount++;
        }
        Animal(int a, int l){
            age = a;
            legCount = l;
            status = false;
            animalCount++;
        }

        ~Animal(){
            animalCount--;
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
        void dead(){status = 1;}

        string toString(){
            stringstream ss;
            ss << name << " "<< age << " " << legCount << " " << status;
            return ss.str();
        }
};
    int Animal::animalCount = 0;
int main(){
    const int amount = 1000;


    Animal cow(12,4);

    assert(cow.getAge() == 12);
    assert(cow.getLegCount() == 4);

    cout << "Constructor check passed" << endl;

    cow.setLegCount(3);
    assert(cow.getLegCount() == 3);

    cow.setAge(cow.getAge() + 1);
    assert(cow.getAge() == 13);

    cow.setName("Moo");
    assert(cow.getName() == "Moo");
    cout << "Set and Get name check passed" << endl;

    cow.setLegCount(3);
    assert(cow.getLegCount() == 3);
    cout << "Set and Get leg count check passed" << endl;

    cow.dead();
    assert(cow.isDead());
    cout << "Animal death check passed rip" << endl;


    assert(cow.toString() == "Moo 13 3 1");



    Animal* animals[amount];
    srand(time(0));
    int randomNum = rand() % 101;
    for (int i = 0; i < amount; i++) {
        animals[i] = new Animal("Cow" + to_string(i + 1), randomNum, 4);
    }



    for (int i = 0; i < amount; i++) {
        animals[i] ;
    }



    for (int i = 0; i < amount; i++) {
        delete animals[i];
    }
    return 0;
}
