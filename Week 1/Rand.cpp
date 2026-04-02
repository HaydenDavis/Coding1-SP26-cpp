//Hayden Davis Coding 1 Spring 2026
//fill out the rest of the code so that it dsiplays the words 
    // then run it


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {

    srand(time(0));
    cout << "Random numbers! /n";

    cout << "Here is our first random number: " << rand() << ".\n";

    int counter = 0;
    while (counter++ < 10) {
        int number = rand();
        int min = 50;
        int max = 100;
        int range = max - min; // 50
        int clampedNumber = ((number % range) + min);

         cout << clampedNumber << endl;
    }

    //Set variables
        //The random number
        //The guess/input
    int randomNumber = (rand() % 11) + 10;
    int number = (rand() % 10) + 1;
    int guess = -1;
    int totalGuesses = 0;
    cout << "I'm thinking of a number between 1 and 10, try to guess it. \n";

    while (true) {
    //ask for player input between 1 and 10
    cin >> guess;
    totalGuesses++;
    //Say higher, lower, or correct in response
        //if incorrect, loop again to ask
        if (guess > number) {
            cout << "Too high! Please guess again.\n";
        }

        else if (guess < number) {
            cout << "Too low! Please guess again.\n";
        }

        //if correct, end loop and display victory message
        else {
            cout << "You guessed correcctly!\n" << "It only took you " << totalGuesses << " guesses!";
            break;
        }

    }

    return 0;
}