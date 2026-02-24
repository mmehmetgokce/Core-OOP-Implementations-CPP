#include <iostream>
#include <vector>
#include <string>

class Food {
    std::string name;
public:
    Food(const std::string& name) : name(name) {}
    std::string getName() const {
        return name;
    }
};

class Meat : public Food {
public:
    Meat() : Food("meat") {}
};

class Fruit : public Food {
public:
    Fruit() : Food("fruit") {}
};

class Insects : public Food {
public:
    Insects() : Food("insects") {}
};

class OtherFishes : public Food {
public:
    OtherFishes() : Food("other fishes") {}
};

class Animal {
protected:
    std::string name;
    int age;
public:
    Animal(const std::string& name, int age) : name(name), age(age) {}
    virtual void makeSound() = 0;
    virtual void eat(const Food& food) = 0;

    virtual void sleep() {
        std::cout << name << " is sleeping." << std::endl;
    }
    virtual void move() = 0;

    virtual void layEggs() {
        std::cout << name << " cannot lay eggs." << std::endl;
    }
    virtual void giveBirth() {
        std::cout << name << " cannot give birth." << std::endl;
    }

    virtual void climb() {
        std::cout << name << " cannot climb." << std::endl;
    }
    virtual void fly() {
        std::cout << name << " cannot fly." << std::endl;
    }

    virtual ~Animal() {}
};

class Mammal : public Animal {
public:
    Mammal(const std::string& name, int age) : Animal(name, age) {}
    void giveBirth() {
        std::cout << name << " is giving birth." << std::endl;
    }
    void makeSound() override {
        std::cout << name << " makes a mammal sound." << std::endl;
    }
    void move() override {
        std::cout << name << " is moving as a mammal." << std::endl;
    }
};

class Monkey : public Mammal {
public:
    Monkey(const std::string& name, int age) : Mammal(name, age) {}
    void makeSound() override {
        std::cout << name << " chatters." << std::endl;
    }
    void move() override {
        std::cout << name << " swings from tree to tree." << std::endl;
    }
    void climb() override {
        std::cout << name << " climbs trees skillfully." << std::endl;
    }
    void eat(const Food& food) override {
        std::cout << name << " eats the " << food.getName() << "." << std::endl;
    }
};

class Bat : public Mammal {
public:
    Bat(const std::string& name, int age) : Mammal(name, age) {}
    void makeSound() override {
        std::cout << name << " screeches." << std::endl;
    }
    void move() override {
        std::cout << name << " flies through the night." << std::endl;
    }
    void fly() override {
        std::cout << name << " flies silently." << std::endl;
    }
    void eat(const Food& food) override {
        std::cout << name << " eats the " << food.getName() << "." << std::endl;
    }
};

class Lion : public Mammal {
public:
    Lion(const std::string& name, int age) : Mammal(name, age) {}
    void makeSound() override {
        std::cout << name << " roars." << std::endl;
    }
    void move() override {
        std::cout << name << " runs swiftly." << std::endl;
    }
    void eat(const Food& food) override {
        std::cout << name << " devours the " << food.getName() << "." << std::endl;
    }
};

class Bird : public Animal {
public:
    Bird(const std::string& name, int age) : Animal(name, age) {}
    void layEggs() {
        std::cout << name << " lays eggs." << std::endl;
    }
    void makeSound() override {
        std::cout << name << " chirps." << std::endl;
    }
    void move() override {
        std::cout << name << " is flying." << std::endl;
    }
    void fly() override {
        std::cout << name << " flies gracefully." << std::endl;
    }
};

class Eagle : public Bird {
public:
    Eagle(const std::string& name, int age) : Bird(name, age) {}
    void makeSound() override {
        std::cout << name << " screams majestically." << std::endl;
    }
    void move() override {
        std::cout << name << " soars high." << std::endl;
    }
    void eat(const Food& food) override {
        std::cout << name << " tears apart the " << food.getName() << " with its beak." << std::endl;
    }
};

class Fish : public Animal {
public:
    Fish(const std::string& name, int age) : Animal(name, age) {}
    void layEggs() {
        std::cout << name << " lays eggs in water." << std::endl;
    }
    void makeSound() override {
        std::cout << name << " does not make sound." << std::endl;
    }
    void move() override {
        std::cout << name << " is swimming." << std::endl;
    }
};

class Shark : public Fish {
public:
    Shark(const std::string& name, int age) : Fish(name, age) {}
    void makeSound() override {
        std::cout << name << " silently stalks its prey." << std::endl;
    }
    void move() override {
        std::cout << name << " swims rapidly." << std::endl;
    }
    void eat(const Food& food) override {
        std::cout << name << " shreds the " << food.getName() << " with its teeth." << std::endl;
    }
};

class Reptile : public Animal {
public:
    Reptile(const std::string& name, int age) : Animal(name, age) {}
    void layEggs() {
        std::cout << name << " lays eggs." << std::endl;
    }
    void makeSound() override {
        std::cout << name << " makes a reptile sound." << std::endl;
    }
    void move() override {
        std::cout << name << " is crawling." << std::endl;
    }
    void climb() override {
        std::cout << name << " climbs rocks and logs." << std::endl;
    }
};

class Snake : public Reptile {
public:
    Snake(const std::string& name, int age) : Reptile(name, age) {}
    void makeSound() override {
        std::cout << name << " hisses." << std::endl;
    }
    void move() override {
        std::cout << name << " slithers silently." << std::endl;
    }
    void climb() override {
        std::cout << name << " climbs trees and rocks." << std::endl;
    }
    void eat(const Food& food) override {
        std::cout << name << " swallows the " << food.getName() << " whole." << std::endl;
    }
};

int main() {
    std::vector<Animal*> zoo;
    zoo.push_back(new Monkey("Monkey", 4));
    zoo.push_back(new Bat("Bat", 6));
    zoo.push_back(new Lion("Lion", 5));
    zoo.push_back(new Eagle("Eagle", 3));
    zoo.push_back(new Shark("Shark", 7));
    zoo.push_back(new Snake("Snake", 2));

    Fruit fruit;
    Meat meat;
    Insects insects;
    OtherFishes fishFood;

    for (auto animal : zoo) {
        animal->makeSound();
        animal->move();

        if (dynamic_cast<Monkey*>(animal)) {
            animal->eat(fruit);
        }
        else if (dynamic_cast<Bat*>(animal)) {
            animal->eat(insects);
        }
        else if (dynamic_cast<Lion*>(animal)) {
            animal->eat(meat);
        }
        else if (dynamic_cast<Eagle*>(animal)) {
            animal->eat(meat);
        }
        else if (dynamic_cast<Shark*>(animal)) {
            animal->eat(fishFood);
        }
        else if (dynamic_cast<Snake*>(animal)) {
            animal->eat(meat);
        }

        animal->sleep();
        animal->climb();
        animal->fly();
        animal->giveBirth();
        animal->layEggs();
    }

    for (auto animal : zoo) {
        delete animal;
    }

    return 0;
}