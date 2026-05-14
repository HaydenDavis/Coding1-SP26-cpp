#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

string input;

// Create the CritteronMon class
    // add health and hunger
    // function to train, eat and fight
         // Fight loop having attack, heal, and run away.
    // fighting and training removes 1 hunger, when 5 or over,
    // give a warning, and at 10 cannot train or fight.

class baseCritterMon {
    private:
    // variables
    string name;
    int health;
    int damage;
    int hunger;

    public:

    // constructors

    baseCritterMon(string givenName) {
        name =  givenName;
        health = 100;
        damage = 15;
        hunger = 0;
    }

    // misc. functions

    void train() {

        cout << "Let's train your CritterMon!\n";

        int randTrain;
        randTrain = rand() % 3 + 1;

        if(randTrain == 1) {
            cout << "This training session didn't do much... \n";
        }
        else if(randTrain == 2) {
            cout << "This training session gave a boost to your critters health!\n";
            setHealth(rand() % 15 + 5);
        }
        else if(randTrain == 3) {
            cout << "This training session gave a boost to your critters damage!\n";
            setHealth(rand() % 10 + 1);
        }

    }

    void inspect() {
        cout << name << " has " << health << " health, with a damage of " << damage;
        cout << ". It's hunger is at a " << hunger << " out of 10.\n";
    }

    //getters

    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getDamage() {
        return damage;
    }

    int getHunger() {
        return hunger;
    }

    //setters

    void setName(string givenName) {
        name = givenName;
    }

    void setHealth(int newHealth) {
        health += newHealth;
    }

    void setDamage(int newDamage) {
        damage += newDamage;
    }

    void addHunger(int newHunger) {
        hunger += newHunger;
    }

    void removeHunger () {
        hunger = 0;
    }

};

int main () {
    cout << "Time to create your CritterMon!\n";
    cout << "What is the name/type of your CritterMon?\n";

    getline(cin,input);
    
    baseCritterMon critter(input);

    critter.inspect();

    cout << "Time to start your critterMons journey!\n";

    //GAMEPLAY LOOP
    while(true) {
        cout << "command list: \n 'feed' to replenish hunger \n 'train' to train \n 'battle' to battle other Critters!\n";

        cout << "Please type your command: ";
        
        getline(cin,input);

    
        if(input == "feed") {
            
            if (critter.getHunger() == 0) {
                cout << "Your critter is already full! Please try again later. \n";
            } 
            else {

                critter.removeHunger();
            
            cout << "Your critter was fed!";
                
            }
        }

        else if (input == "train" ) {

        }

        else if (input == "battle") {

        }
        else {
            cout << "Try again.\n \n";
        }
        

    }




    return 0;
}
