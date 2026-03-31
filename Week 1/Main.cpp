// Hayden Davis Coding 1 Spring
// Variable and Logic

// compile with Developer Command Prompt 
//'cl /EHsc main.cpp' is is what you type to compile 
// 'main' or 'main.exe' to run the program

#include <iostream>
using namespace std;

int main() {
    cout << "Let's learn about variables and logic \n";

    //Declaring and defining variables
    int playerAge = -1;
    string playerName = "Darth Vader";
    float happinessPercent = 0.61f;
    bool keepPlaying = true;

    //Just like a branch in UE
    if(playerAge == -1) {
        cout << "How old are you? \n";
        cin >> playerAge;

        if(playerAge <= 12) {
            cout << "Im sorry, but you are the youngest ever! \n";
            return 0; // Quit the game early
        }
        else {
            cout << "Wow," << playerAge << " years, that is very old! \n";
        }
    } // end of if(playerAge)

    if (playerName == "Darth Vader") {
        cout << "is your name " << playerName << "?\n";
        string input;
        cin >> input;
        // the OR operator || means that if any test evluates to true, the if statement is true
        if(input == "yes" || input == "Yes" || input == "yeah" || input == "Yeah") {
            cout << "Well, thats convenient!\n";
        }
        else {
            cout << "What is your name?\n";
            cin >> playerName;
        }

        cout << "Hello " << playerName << ".\n";
    } // end of if(playerName)

    bool debug = false;
    // the AND operator '&&' requires that all tests are true
    if(playerAge == 18 && playerName == "Hayden") {
        debug = true;
        cout << "Hello creator. Debug mode is now ON. \n";
    } //end of if(age && name)

    if(debug) {
        cout << "playerAge = " << playerAge << ".\n";
        cout << "playerName = " << playerName << ".\n";
        cout << "happinessPercent = " << happinessPercent << ".\n";
        cout << "keepPlaying = " << keepPlaying << ".\n";
    }

    return 0;
} // end of main()