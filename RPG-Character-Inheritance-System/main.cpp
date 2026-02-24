#include <iostream>
#include <string>
using namespace std;

// Base Class
class Character {
protected:
    string name;
    int level;
    int health;

public:
    Character(const string& name, int level, int health)
        : name(name), level(level), health(health > 0 ? health : 0) {}

    virtual ~Character() = default; // Virtual destructor for polymorphism

    // Print character information (virtual for polymorphism)
    virtual void printInfo() const {
        cout << "Name: " << name << ", Level: " << level << ", Health: " << health;
    }

    // Getters and setters
    string getName() const { return name; }
    void setName(const string& newName) { name = newName; }

    int getLevel() const { return level; }
    void setLevel(int newLevel) { level = newLevel; }

    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = max(0, newHealth); } // Health cannot be negative
};

// Warrior Class (Derived)
class Warrior : public Character {
private:
    int strength;

public:
    Warrior(const string& name, int level, int health, int strength)
        : Character(name, level, health), strength(strength) {}

    void useSword(Character& target) {
        int damage = strength;
        target.setHealth(target.getHealth() - strength);
        cout << name << " used sword on " << target.getName()
            << " causing " << strength << " damage." << endl;
    }

    void printInfo() const override {
        Character::printInfo();
        cout << ", Strength: " << strength;
    }
};

// Mage Class (Derived)
class Mage : public Character {
private:
    int mana;

public:
    Mage(const string& name, int level, int health, int mana)
        : Character(name, level, health), mana(mana) {}

    void useSpell() {
        cout << name << " used spell." << endl;
    }

    void printInfo() const override {
        Character::printInfo();
        cout << ", Mana: " << mana;
    }
};

// Archer Class (Derived)
class Archer : public Character {
private:
    int arrows;

public:
    Archer(const string& name, int level, int health, int arrows)
        : Character(name, level, health), arrows(arrows) {}

    void useArrow(Character& target) {
        if (arrows > 0) {
            int damage = level;
            target.setHealth(target.getHealth() - damage);
            arrows--;
            cout << name << " shoots an arrow at " << target.getName()
                << " causing " << damage << " damage. Remaining arrows: " << arrows << "." << endl;
        }
        else {
            cout << name << " has no arrows left!" << endl;
        }
    }

    void printInfo() const override {
        Character::printInfo();
        cout << ", Arrows: " << arrows;
    }
};

// Class implementations

int main() 
{
    // name, level, health, ...
    Warrior warrior("Ahmet", 33, 200, 30);
    Mage mage("Mehmet", 65, 90, 40);
    Archer archer("Zeynep", 50, 95, 3);

    cout << "------------------------------\n";
    cout << "Character Information:\n";
    warrior.printInfo();
    cout << "\n---------------\n";
    mage.printInfo();
    cout << "\n---------------\n";
    archer.printInfo();
    cout << "\n------------------------------\n";

    cout << "Characters in Action:\n";
    warrior.useSword(mage);
    cout << "---------------\n";
    mage.useSpell();
    cout << "---------------\n";
    archer.useArrow(mage);
    cout << "---------------\n";
    archer.useArrow(mage);
    cout << "---------------\n";
    warrior.useSword(archer);
    cout << "---------------\n";
    archer.useArrow(warrior);
    cout << "---------------\n";
    archer.useArrow(warrior);

    cout << "------------------------------\n";
    cout << "Updated Character Information:\n";
    warrior.printInfo();
    cout << "\n---------------\n";
    mage.printInfo();
    cout << "\n---------------\n";
    archer.printInfo();
    cout << "\n------------------------------\n";

    return 0;
}