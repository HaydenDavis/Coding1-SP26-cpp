// Hayden Davis Coding 1 Week 13
//Functions

#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // For time()
#include <vector>

using namespace std;

/*
Functions
    returnType, FunctionName (input paramaters) {code}
*/

string input;

void sayHello() {
    cout << "hello! \n";
}

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Together they make " << firstNum + secondNum << ".\n";
}

int dieRoll(int side = 6, int min = 1) {
    return rand() % side + min;
}

bool askYesNo(string question = "Do you want to keep playing?\n") {
    while(true) {
        cout << question << "('yes'/'no')\n";
        getline(cin, input);

        if(input == "yes" || input == "Yes") {
            return true;
        }
        else if(input == "no" || input == "No") {
            return false;
        }
        else {
            cout << "I did not understand. Please type 'yes' or 'no'. \n";
        }
    }
}

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}

void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    getline(cin,input);
    
    vec.push_back(input);
    showVec(vec);
}

int main() {
    srand(time(0));
    vector<string> names = {"finn", "Jake", "Marceline", 
                            "BMO", "Princess BubbleGum"};
    cout << "Finally, functions!\n";

    sayHello();

    doAddition(6,9);
    doAddition(809,11);

    cout << "Lets roll our first diece! our first number is " << dieRoll(6) << ".\n";

    if(askYesNo()) {
        cout << "Lets start the next level!\n";
    }
    else {
        cout << "Thanks for playing!\n";
    }

    if(askYesNo("Do you like Nintendo?")) {
        cout << "Me too! Whats your favorite game?\n";
    }
    else {
        cout << "Right, right, right.... side eye\n";
    }

    return 0;
}
