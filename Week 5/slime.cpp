//Inherticance, Vectors of classes, and slime battling

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<string> names = {"Alfred", "Barbara", "Sandra", "Quentin", "Glenn", "Betty"};

class baseSlime {
    public:
    string name;
    int health;
    int damage;

    baseSlime() {
        cout << "A new slime has been formed!\n";
        name = names[rand() % names.size()] + " Slime";
        health = rand() % 4 + 4;
        damage = rand() % 3 + 3;
    }

    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << "and " << damage << " damage.\n";
    }

    bool attack(baseSlime& opponent) {
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if (opponent.health <= 0) {
            return true;
        }
        else {
            return false;
        }


    }
};

class bossSlime : public baseSlime {
    public:
    int damageMultiplier = 3;

    bossSlime () {
        name = "boss";
        damage = damage * damageMultiplier;
    }

    void taunt() {
        cout << "I will crush you with my slime!\n";
    }

    bool attack(baseSlime& opponent) {
        cout << "This is a boss attack";
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";
        if (opponent.health <= 0) {
            return true;
        }
        else {
            return false;
        }

    }

};

int main () {
    srand(time(0));
    cout << "SLIME BATTLES!\n";

    baseSlime gerald;
    gerald.name = "gerald";
    gerald.hello();

    bossSlime destroyer;
    destroyer.name = "Destroyer";
    destroyer.hello();
    destroyer.taunt();

    cout << "Gerald is feeling cheeky...\n";
    gerald.attack(destroyer);

    cout << "Destroyer is enraged!\n";
    if(destroyer.attack(gerald)) {
        cout << "Gerald is no more.\n";
    }

    vector<baseSlime> sludge(6);

    cout << "Here's our sludge of slimes:\n\n";
    for(auto& slime : sludge) {
        cout << slime.name << "\n";
    }

    random_shuffle(sludge.begin(), sludge.end());

    auto& a = sludge[0];
    auto& b = sludge[1];

    while(a.health > 0 && b.health > 0) {
        if(a.attack(b)) {
            cout << b.name << " has been defeated by " << a.name << ".\n";
        }
        else {
            if(b.attack(a)) {
                cout << a.name << " has been defeated by ";
                cout << b.name << ".\n";
            }
        }
    }

    return 0;
}