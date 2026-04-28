#include <iostream>
#include <string>
using namespace std;

//constructors
//getters and setters


class robot {
private:
    string name;
    int charge;
    int boredom;
public:
    //contructor, sets up the class with input variables, 
    //no type, must be named same as class!!!!!!


    robot(string givenName, int givenCharge, int givenBoredom) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }

    robot() {
        name = "robot";
        charge = 10;
        boredom = 10;
        status();
    }

    //Getters

    string getName() {
        return name;
    }
    int getCharge() {
        return charge;
    }

    int getBoredom() {
        return boredom;
    }

    // Setters

    void setName(string givenName) {
        if(givenName.size() <= 5) {
            name = givenName;
        }
        else {
            cout << "error: " << givenName << " is too long!\n";
        }
    }

    void setCharge(int givenCharge) {
        if(givenCharge < 0){
            charge = 0;
        }
        else if(givenCharge > 100) {
            charge = 100;
        }
        else {
            charge = givenCharge;
        }
    }

    voic changeChargeBy(int amount = 1) {
        setCharge(charge += amount);
    }

    void setBoredom(int givenBoredom) {
        if(givenBoredom > 20) {
            boredom = 20;
        }
        boredom = givenBoredom;
    }

    void status() {
        cout << "Hello, my name is " << name;
        cout << " and my charge is " << charge << ".\n";
        cout << "I am ";

        if (boredom < 5) cout << "happy";
        else if (boredom < 10) cout << "bored";
        else if (boredom < 15) cout << "frustrated";
        else cout << "ENRAGED";

        cout << ".\n";
    }
    
};

int main() {
    cout << "Classes!\n";

    robot artoo("R2-D2",45,3);
    // artoo.name = "R2-D2";
    // artoo.charge = 45;

    robot threepio;
    threepio.setName("C-3P0");
    threepio.setCharge(96);
    threepio.setBoredom(4);

    threepio.status();

    while(threepio.getCharge() < 15) {
        if(artoo.getCharge() > 0) {
            artoo.changeChargeBy(-1);
            threepio.changeChargeBy(1);
        }
        else {
            cout << "Artoo is out of energy!\n";
            break;
        }
    }

    artoo.status();
    threepio.status();

    return 0;
}