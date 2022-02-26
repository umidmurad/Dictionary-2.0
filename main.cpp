// Created by Umid Muradli on 2/23/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include "sstream"
#include <vector>
#include "algorithm"

using namespace std;

int main() {
    string line;
    fstream FileReader;
    vector<string> startingvector;
    FileReader.open("../Data.CS.SFSU.txt", ios::in);
    if (FileReader.is_open()) {
        while (!FileReader.eof()) {
            while (getline(FileReader, line)) {
                string word, pos, def, posAndDef;
                char pipe = '|';
                char arrow = ' -';

                word = line.substr(0, line.find('|'));
                cout << "\n" << word << "-----------------------------" << endl;
                line.erase(0, line.find('|') + 1);
                stringstream pipeSep(line);

                size_t defsAmount = count(line.begin(), line.end(), arrow);
                for (int i = 0; i < defsAmount; i++) {
                    getline(pipeSep, posAndDef, pipe); // pipe = "|"

                    pos = posAndDef.substr(0, posAndDef.find('-')-1);
                    cout << pos << ": ";
                    def = posAndDef.erase(0, posAndDef.find('-') + 5);
                    cout << def << endl;
                }

            }
        }


    } else { //if cant open the file
        cout << "Error opening the file.";
    }

    FileReader.close();
    //for ( int i = 0; i < startingvector.size(); i++)
    //{cout << startingvector[i] <<endl;}

//    //this works for getting speech
//    string token;
//    string del = "|";
//    size_t pos = line.find(del);
//    size_t space = line.find(' ');
//    token = line.substr(pos+1, space-pos);
//    startingvector.push_back(token);

// //reads words,
//    string tokenw;
//    string del = "|";
//    size_t pos = line.find(del);
//    //size_t space = line.find(' ');
//    tokenw = line.substr(0, pos);
//    startingvector.push_back(tokenw);
    return 0;
}
