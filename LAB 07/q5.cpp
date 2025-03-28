#include <iostream>
using namespace std;

class Character {
protected:
    string characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
public:
    Character(string id, string n, int lvl, int hp, string weapon = "") : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}
    virtual void attack() {
        cout << name << " attacks with " << weaponType << "!" << endl;
    }
    virtual void defend() {
        cout << name << " defends against the attack!" << endl;
    }
    virtual void displayStats() {
        cout << "Character ID: " << characterID << "\nName: " << name << "\nLevel: " << level << "\nHealth: " << healthPoints << "\nWeapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;
public:
    Warrior(string id, string n, int lvl, int hp, int armor, int damage, string weapon = "Sword")
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}
    void attack() override {
        cout << name << " swings their " << weaponType << " for " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;
public:
    Mage(string id, string n, int lvl, int hp, int mana, int spell, string weapon = "Staff")
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}
    void defend() override {
        cout << name << " conjures a magical barrier using " << manaPoints << " mana points!" << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    double rangedAccuracy;
public:
    Archer(string id, string n, int lvl, int hp, int arrows, double accuracy, string weapon = "Bow")
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}
    void attack() override {
        cout << name << " shoots an arrow with " << (rangedAccuracy * 100) << "% accuracy! " << endl;
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;
public:
    Rogue(string id, string n, int lvl, int hp, int stealth, int agil, string weapon = "Dagger")
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agil) {}
    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << endl;
    }
};

int main() {
    Warrior w1("1002", "Thorin", 10, 150, 50, 30);
    Mage m1("1001", "Gandalf", 12, 120, 200, 40);
    Archer a1("4005", "Legolas", 11, 130, 30, 0.85);
    Rogue r1("3006", "Ezio", 9, 110, 80, 90);

    w1.displayStats();
    w1.attack();
    cout << "\n";
    
    m1.displayStats();
    m1.defend();
    cout << "\n";
    
    a1.displayStats();
    a1.attack();
    cout << "\n";
    
    r1.displayStats();
    
    return 0;
}
