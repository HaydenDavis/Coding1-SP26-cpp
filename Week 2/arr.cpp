//Arrays, For Loops, Enums, and Switch Statements

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));

    cout << "Lets make some arrays! \n";


    // Arrays cannot change their size
    // Arrays dont know where the last index is
    //Arrays are a list of similar variable types
    // Arrays are ordered

    int scores[5]; // This is creating an intiger array with a size of 5.

    scores[0] = 103;
    scores[1] = 2004;
    scores[2] = 900;
    scores[3] = 47542;
    scores[4] = 23;


    cout << "The first score is " << scores[0] << ".\n"; 

    cout << "Here are all of the scores\n";
    int index = 0;
    while (index < 5) {
        cout << scores[index] << ".\n";
        index++;
    }

    // for loop has the 'iterator'built in.
    cout << "Using a for loop:\n";
    for(int i = 0; i < 5; i++) {
        cout << scores[i] << "\n";
    }

    string names[10];//This is the string of names
    string input;
    index = 0; //reset index

    cout << "Please input names for each array index: \n";
    while(index < 10) {
        cout << "type name or 'done': ";
        cin >> input;

        if (input == "done") {
            cout << "\nDone adding names. \n";
            break;
        }

        names[index++] = input;
    }

    for(int i =0; i < index; i++) {
        if(names[i] == "") {
            continue;
        }
        
        cout << names[i] << "\n";
    }

    string newNames[] =  {"Mario", "Luigi", "Peach", 
                            "Captain Toad","Yoshi","Bowser"
                            ,"Rosalina", "Bowser Jr."
                        };
    
    cout << "Here are the new names:\n";
    for(int i = 0; i < 8; i++) {
        cout << i + 1 << ". " << newNames[i] << "\n";
    }

    int randIndex = rand() % 8;
    string character = newNames[randIndex];
    
    cout << character << ", lets talk about them.\n";

    enum favor {LOVE, LIKE, DISLIKE, LOATHE};
    enum difficulty {EASY, NORMAL, HARD, IMPOSSIBLE};
    enum shirtSize {EXTRA_SMALL, SMALL, MEDIUM, LARGE, EXTRA_LARGE};
    switch(rand()% 4) {
        case LOVE:
            cout << "I love " << character << ".\n";
            break;  
        case LIKE:
            cout << "I like " << character << ".\n"; 
            break;  
        case DISLIKE:
            cout << "I dislike " << character << ".\n"; 
            break;  
        case LOATHE:
            cout << "I loathe " << character << ".\n";
            break;  
            
    }
    return 0;
}