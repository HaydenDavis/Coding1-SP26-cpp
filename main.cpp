// Hayden Davis Coding 1 Spring 2026
// My first C++ Program

#include <iostream> // in out stream, for sending text to the console

using namespace std; // So we dont have to type "std::" all the time

// Here is where we start the program

int main() {
// Variables declared at the top is the best practive
    string playerName;
    cout << "What is your name, player?";

    //Assign whatever the player types as the value of playerName
    cin >> playerName;

    // greet the player by name
    cout << "Hello " << playerName << "." << endl;

    // cout << "Hello World!" << endl; //e cout = console out, ndl = end line

    return 0;   // end the program
}