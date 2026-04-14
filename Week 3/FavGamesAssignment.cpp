//CREATE A C++ PROGRAM THAT WILL ALLOW THE USER TO:
//'ADD' A GAME
//'EDIT' A GAME
//'REMOVE' A GAME
//'SHOW' ALL GAMES (SORTED)
//'QUIT'

//USE VECTORS AND ITERATORS AND ALGORITHMS TO DO SO
//USE PSEUDOCODE TO ORGANIZE YOUR THOUGHTS
//SHOW THE AVAILABLE COMMANDS TO THE USER AT THE TOP OF EACH LOOP
//THE GAMES NEED TO SAVE BETWEEN LAUNCHES OF THE PROGRAM
//THE USER SHOULD BE ABLE TO TYPE THE COMMAND THEY WANT AS A WORD

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <algorithm>        // for find(), sort(), random_shuffle()

using namespace std;

int main(){

    vector<string> favGames = {"Overwatch", "Fortnite", "Until Dawn", "Dead by Daylight", "Marvel Rivals"};
    string input; // int numberInput = stoi(input);
    
    do {

        cout << "What would you like to do?\n";
        cout << "You can type 'Add', 'Edit', 'Remove', 'Show', and 'Quit'.\n";

        getline(cin, input);        // get input from the player

        if(input == "Add") {
            cout << "What is the name of the game you would like to add to your favorites?\n";

            getline(cin,input);
            favGames.push_back(input); //Gets the players input and adds it to the vector

            cout << "Successfully added " << input << " as a new favorite game!\n";

        }

        else if (input == "Edit") {
            
        }

        else if (input == "Remove") {

        }

        else if (input == "Show") {
            sort(favGames.begin(), favGames.end()); //Sorts the vector alphabetically
            
            cout << "Here are your favorite games:\n";
            for(int i = 0; i < favGames.size(); i++ ) {
                cout << "    " << favGames[i] << "\n";
            }

        }

        else if (input == "Quit") {
            cout << "Thank you for playing!" ;
            break;
        }
        else {
            cout << "Please enter a valid command.\n";
        }

    
    } while(true);

    return 0;
}