////mindaugas.kalvinskas@mif.stud.vu.lt 2413953
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

class Animal{
    static int animalCount;
    static int animalIdCounter;

    private:
        string name;
        int age, legCount;
        bool isAlive;
        int animalId;

    public:
        Animal(int age, int legCount, string name){
            setName(name);
            setAge(age);
            setLegCount(legCount);
            alive();
            animalCount++;
            animalId = animalIdCounter++;
        }
        Animal(int age, int legCount){
            setAge(age);
            setLegCount(legCount);
            alive();
            animalCount++;
            animalId = animalIdCounter++;
        }
        ~Animal(){
            animalCount--;
        }

        void setName(string name){
            this->name = name;
        }
        string getName(){
            return name;
        }

        void setAge(int newAge){
            if(newAge>=0)
                age = newAge;
            else
                throw (newAge);
        }
        int getAge(){
            return age;
        }
        int getId(){
            return animalId;
        }
        static int getCount(){
            return animalCount;
        }

        void setLegCount(int legCount){
            this->legCount = legCount;
        }
        int getLegCount(){
            return legCount;
        }

        bool getIsAlive(){
            return isAlive;
        }
        void dead(){
            isAlive = 0;
        }
        void alive(){
            isAlive = 1;
        }
        string toString(){
            stringstream ss;
            ss << name << " "<< age << " " << legCount << " " << isAlive;
            return ss.str();
        }
};


int Animal::animalCount = 0;
int Animal::animalIdCounter = 0;


int main(){
    try{


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
        assert(!cow.getIsAlive());
        cout << "Animal death check passed rip" << endl;


        assert(cow.toString() == "Moo 13 3 0");
        cout << "To string check passed" << endl;


        Animal* animals[amount];
        // example: let's say we need to sort thorough data and find if some animals are dead later
        for (int i = 0; i < amount; i++) {
            animals[i] = new Animal(i%10, 4, "Cow" + to_string(i + 1));
            if (animals[i]->getAge() >= 5)
                animals[i]->dead();
        }

        assert(!animals[6]->getIsAlive());
        assert(!animals[16]->getIsAlive());
        assert(!animals[126]->getIsAlive());
        assert(!animals[996]->getIsAlive());


        cout << "Is dead on generated list test passed" << endl;



        assert(Animal::getCount() == 1001);
        cout << "Object count check passed" << endl;

        assert(cow.getId() == 0);
        assert(animals[12]->getId() == 13);
        assert(animals[999]->getId() == 1000);

        cout << "Id check passed" << endl;





        for (int i = 0; i < amount; i++) {
            delete animals[i];
        }

    }
    catch (int age){
        cout << "Age must be positive" << endl;
    }
    assert(Animal::getCount() == 0);
    cout << "Object delete count check passed" << endl;

    return 0;
}
