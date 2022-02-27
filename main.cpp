// Created by Umid Muradli on 2/23/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include "sstream"
#include <vector>
#include "algorithm"
#include "Test.h"

using namespace std;

int main() {
    string line;
    fstream FileReader;
    vector<string> startingvector;
    vector< pair<string, pair<string, string> > > myvec;
    FileReader.open("../Data.CS.SFSU.txt", ios::in);
    if (FileReader.is_open()) {
        while (getline(FileReader, line)) {
            string word, pos, def, posAndDef;
            char pipe = '|';
            char arrow = ' -';
            size_t defsAmount = count(line.begin(), line.end(), pipe); //moved here
            word = line.substr(0, line.find('|'));
            cout << "\n" << word << "-----------------------------" << endl;
            line.erase(0, line.find('|') + 1);
            stringstream pipeSep(line);

            //size_t defsAmount = count(line.begin(), line.end(), arrow); moved this up, and it counts pipe, instead of arrow
            for (int i = 0; i < defsAmount; i++) {
                getline(pipeSep, posAndDef, pipe); // pipe = "|"

                pos = posAndDef.substr(0, posAndDef.find(arrow) - 1);
                cout << pos << ": ";
                def = posAndDef.erase(0, posAndDef.find(arrow) + 5);
                cout << def << endl;

                myvec.push_back(make_pair(word, make_pair(pos,def)));   // new
            }
        }
        sort(myvec.begin(), myvec.end()); //new

    }

    else { //if cant open the file
        cout << "Error opening the file.";
    }

    FileReader.close();

    //new after this
    string input;
    while(input != "!q") {

        cout << "\n\nType something here:   ";
        cin >> input;
        cout <<"\n|\n";
        for (int i = 0; i < myvec.size(); i++) {

            //while (input == myvec[i].first) {

                cout  <<endl << myvec[i].first << " [" << myvec[i].second.first
                     << "]  : " << myvec[i].second.second <<endl ;
                //i++;
            //}

        }
        cout <<"\n|\n";

    }






    return 0;
}
