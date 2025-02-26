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
            isAlive = true;
            animalCount++;
            animalId = animalIdCounter++;
        }
        Animal(int age, int legCount){
            setAge(age);
            setLegCount(legCount);
            isAlive = true;
            animalCount++;
            animalId = animalIdCounter++;
        }
        ~Animal(){
            animalCount--;
        }

        void setName(string n){
            name = n;
        }
        string getName(){
            return name;
        }

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
        int getAge(){
            return age;
        }
        int getId(){
            return animalId;
        }
        static int getCount(){
            return animalCount;
        }

        void setLegCount(int l){
            legCount = l;
        }
        int getLegCount(){
            return legCount;
        }

        bool isDead(){
            return isAlive;
        }
        void dead(){
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
    {


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
    cout << "To string check passed" << endl;


    Animal* animals[amount];
    // example: let's say we need to sort thorough data and find if some animals are dead later
    for (int i = 0; i < amount; i++) {
        animals[i] = new Animal(i%10, 4, "Cow" + to_string(i + 1));
        if (animals[i]->getAge() >= 5)
            animals[i]->dead();
    }

    assert(animals[6]->isDead());
    assert(animals[16]->isDead());
    assert(animals[126]->isDead());
    assert(animals[996]->isDead());


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
    assert(Animal::getCount() == 0);
    cout << "Object delete count check passed" << endl;

    return 0;
}
