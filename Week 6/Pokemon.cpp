#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>      // file stream

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
    int maxHealth;
    int health;
    int damage;
    int hunger;
    bool isAlive;
    vector<string> namesList;
    string randName;

    public:

    // constructors

    baseCritterMon(string givenName) {
        name =  givenName;
        maxHealth = 100;
        health = 100;
        damage = 15;
        hunger = 0;
        isAlive = true;

        
        ifstream file("names.txt"); 
        while (getline(file, randName)) {
            namesList.push_back(randName);
        }
    }

    // misc. functions

    void train() {
        if (hunger < 10) {
        cout << "Let's train your CritterMon!\n";

        int randTrain;
        randTrain = rand() % 3 + 1;

        if(randTrain == 1) {
            cout << "This training session didn't do much... \n";
        }
        else if(randTrain == 2) {
            cout << "This training session gave a boost to your critters health!\n";
            setMaxHealth(rand() % 15 + 5);
        }
        else if(randTrain == 3) {
            cout << "This training session gave a boost to your critters damage!\n";
            setDamage(rand() % 10 + 1);
        }

        addHunger(1);
        }
        else {
            cout << "You must feed your critter before trying to train it.\n";
        }

    }

    void inspect() {
        cout << name << " has " << health << " health out of " << maxHealth <<  ", with a damage of "  << damage;
        cout << ". It's hunger is at a " << hunger << " out of 10.\n";
    }

    void beginAttack() {
        if (hunger < 10 && isAlive) { 
            int randIndex = rand() % namesList.size(); 
            bool activeBattle  = true;
            int enemyDamage;
            int enemyMaxHealth;
            int enemyHealth;
            bool hasHealed = true;

            cout << "A wild " << namesList[randIndex] << " approaches!\n \n";

            if (hunger >= 5) {
                cout << "Your critter is going to be hungry during this battle!\n";
            }

            enemyMaxHealth = rand() % 250 + 100;
            enemyHealth = enemyMaxHealth;

            while (activeBattle && isAlive) {
            cout << "Attack Commands: \n";
            cout << "'strike' to attack your enemy \n 'heal' to replenish health \n 'flee' to abandon the battle\n \n";
            cout << "Command: ";
                getline(cin,input);

                if (input == "strike") {
                    enemyHealth -= damage;
                    cout << "Your critter attacks for " << damage << " damage, leaving the enemy at " << enemyHealth << " out of " << enemyMaxHealth << " health.\n";
                    if (enemyHealth <= 0) {
                        cout << "Congrats! you have defeated " << namesList[randIndex] << "!\n";
                        activeBattle = false;
                        addHunger(1);
                        break;
                    }
                    else {
                    enemyDamage = rand() % 70 + 25;

                    cout << "The " << namesList[randIndex] << " attacks! it does " << enemyDamage << " damage.\n";

                    recieveDamage(enemyDamage);
                    

                    if (isAlive) {
                    cout << "Your critter has " << health << " health left!\n";
                    cout << "How will you respond?\n";
                    }
                    }

                }
                else if (input == "heal") {
                   if (hasHealed){
                    
                    healHealth();
                    cout << "You have healed up!\n";
                    hasHealed = false;
                   }
                   else {
                    cout << "You have healed up this battle already!\n";
                   }

                }
                else if (input == "flee") {
                    cout << "You have fled!\n";
                    activeBattle = false;
                    addHunger(1);
                }
            } 
        }
        else {
            cout << "You must feed your pet before attempting to battle.\n";
        }

    }

    void feed() {
        if (hunger == 0) {
                cout << "Your critter is already full! Please try again later. \n";
            } 
            else {

                removeHunger();
                cout << "Your critter was fed!\n";
                
            }
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

    bool getIsAlive() {
        return isAlive;
    }

    //setters

    void setName(string givenName) {
        name = givenName;
    }

    void setMaxHealth(int newHealth) {
        maxHealth += newHealth;
        health = maxHealth;
    }

    void recieveDamage(int damageTaken) {
        health -= damageTaken;

        if (health <= 0) {
            cout << "Your critter is critically injured! \n You have lost.";
            isAlive = false;

        }
    }

    void healHealth() {
        health = maxHealth;
    }

    void setDamage(int newDamage) {
        damage += newDamage;
    }

    void addHunger(int newHunger) {
        if (hunger < 10) {
            hunger += newHunger;
            if (hunger >= 5) {
                cout << "Critter is getting hungry!\n";
            }
        }
        else  {
            cout << "Your pet is starving!\n";
        }
    }

    void removeHunger () {
        hunger = 0;
    }

};

int main () {
    srand(time(0));
    cout << "Time to create your CritterMon!\n";
    cout << "What is the name/type of your CritterMon?\n";

    getline(cin,input);
    
    baseCritterMon critter(input);

    critter.inspect();

    cout << "Time to start your critterMons journey!\n";

    //GAMEPLAY LOOP
    while(critter.getIsAlive()) {
        cout << "\ncommand list: \n 'feed' to replenish hunger \n 'train' to train \n 'inspect' to view your pets stats \n 'battle' to battle other Critters!\n";

        cout << "Please type your command: ";
        
        getline(cin,input);

        cout << "\n";

    
        if(input == "feed") {
            
            critter.feed();
            
        }

        else if (input == "train" ) {
            critter.train();
        }

        else if (input == "battle") {

            critter.beginAttack();

        }
        else if (input == "inspect") {
            critter.inspect();
        }
        else {
            cout << "Try again.\n \n";
        }
        

    }




    return 0;
}
