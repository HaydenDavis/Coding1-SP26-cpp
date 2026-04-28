//Writing to and reading from files

#include <iostream>
#include<string>
#include <vector>
#include <fstream>      // file stream

using namespace std;





void read(string path = "save.txt") {
    // open or "load" the ffile (read)
    // make some changes
    // save the file
    // close the file.

    //creates a new var, and try to open a file
    string line;
    ifstream readFile(path);      //input file stream
    if(readFile.is_open()) {
        cout << "the file is open.\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    // after we're done with a file we need to close it
    readFile.close();
}

void write (vector<string>& vec, string path = "save.txt"){
    ofstream writeFile(path);

    if(writeFile.is_open()) {
        for(int i = 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
    }
    else {
        cout << "Couldnt open new writeFile.\n";
    }

    writeFile.close();
}

void read(vector<string>& vec, string path = "save.txt") {
    string line;
    ifstream readFile(path);

    if(readFile.is_open()) {

        while(getline(readFile, line)) {
            vec.push_back(line); // add each line to the vector
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    // after we're done with a file we need to close it
    readFile.close();
}

int main() {
    cout << "Let's write to a file!\n";
    vector<string> favs;
    string input = "asdf";
    string path = "save.txt";

    cout << "what file would you like to open?\ntype 'no' to use default.\n";
    getline(cin,input);
    if(input != "no") {
        cout << "File loaded and/or created.\n \n";
        path = input;
    }

    read(path); // show current names
    read(favs, path); // add names to vecotr

    cout << "What names would you like to add?\n";
    cout << "Enter an empty line to stop.\n";
    
    while (input != "") {
        cout << "> ";
        getline(cin,input);

        if (input == "") {
            break; //stops the code before it can add a blank addition to the vector
        }
        //send to file
        //writeFile << input << endl
        favs.push_back(input);
    }

    write(favs, path);

    return 0;

}