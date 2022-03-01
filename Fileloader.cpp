//
// Created by Umid Muradli on 2/27/22.
//

#include <iostream>
#include <fstream>
#include "sstream"
#include <vector>
#include <algorithm>

using namespace std;
string reWriterSorter(string);
string reWriterInput(string);
vector< pair<string, pair<string, string> > > myvec;

void FileLoader() {
    int wordcounter=0, defcounter=0;
    string line, opener ="/Users/umidmuradli/Documents/GitHub/Dictionary-2.0/Data.CS.SFSU.txt";
    fstream FileReader;
    FileReader.open(opener, ios::in);
    cout <<"! Opening data file... " << opener <<endl;
    while (!FileReader.is_open()) {
        cout <<"<!>ERROR<!> ===> File could not be opened.\n<!>ERROR<!> ===> Provided file path: " << opener <<endl;
        cout <<"<!>Enter the CORRECT data file path: ";
        getline(cin, opener);
        FileReader.open(opener, ios::in); //tries until file is open.
    }
    //once file is open it starts to load the data.
    if (FileReader.is_open()) {
        cout <<"! Loading data...\n";
        while (getline(FileReader, line)) {
            string word, pos, def, posAndDef;

            char pipe = '|', arrow = ' -';
            size_t defsAmount = count(line.begin(), line.end(), pipe); //counts the "|"
            word = line.substr(0, line.find(pipe));
            wordcounter++;
            word = reWriterSorter(word);
            //cout << "\n" << word << "-----------------------------" << endl;
            line.erase(0, line.find(pipe) + 1);
            stringstream pipeSep(line);

            for (int i = 0; i < defsAmount; i++) {
                getline(pipeSep, posAndDef, pipe); // pipe = "|"

                pos = posAndDef.substr(0, posAndDef.find(arrow) - 1);
                //cout << pos << ": ";
                def = posAndDef.erase(0, posAndDef.find(arrow) + 5);
                //cout << def << endl;
                defcounter++;
                def = reWriterSorter(def);

                myvec.push_back(make_pair(word, make_pair(pos, def)));   // new
            }
        }
        sort(myvec.begin(), myvec.end()); //sorts alphabetically.
        cout <<"! Loading completed...\n";
    }
    FileReader.close();
    cout <<endl << "====== DICTIONARY 340 C++ =====" <<endl;
    cout << "------ Keywords: " <<wordcounter <<endl;
    cout << "------ Definitions: " << defcounter <<endl;
}


string reWriterSorter(string str){
    str[0] = toupper(str[0]);
    return str;
}
string reWriterInput(string str){
    for(int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    str[0] = toupper(str[0]);
    return str;
}

