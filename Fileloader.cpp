//
// Created by Umid Muradli on 2/27/22.
//

#include <iostream>
#include <fstream>
#include "sstream"
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

string reWriterSorter(string);

string reWriterInput(string);

vector<pair<string, pair<string, string> > > myVec;

// FileLoader will read text file and separate it by "|"
void FileLoader() {
    string word, pos, def, posAndDef;
    int wordcounter = 0, defcounter = 0;
    string line, opener = "/Users/umidmuradli/Documents/GitHub/Dictionary-2.0/Data.CS.SFSU.txt";
    fstream FileReader;
    FileReader.open(opener, ios::in);
    cout << "! Opening data file... " << opener << endl;
    while (!FileReader.is_open()) {
        cout << "<!>ERROR<!> ===> File could not be opened.\n<!>ERROR<!> ===> Provided file path: " << opener << endl;
        cout << "<!>Enter the CORRECT data file path: ";
        getline(cin, opener);
        FileReader.open(opener, ios::in); //tries until file is open.
    }
    //once file is open it starts to load the data.
    if (FileReader.is_open()) {
        cout << "! Loading data...\n";
        while (getline(FileReader, line)) {

            char pipe = '|';
            size_t defsAmount = count(line.begin(), line.end(), '|');//counts the "|" in each line
            word = line.substr(0, line.find(pipe));
            wordcounter++;
            word = reWriterSorter(word);
            line.erase(0, line.find(pipe) + 1);
            stringstream pipeSep(line);

            for (int i = 0; i < defsAmount; i++) {
                getline(pipeSep, posAndDef, pipe); // pipe = "|"
                pos = posAndDef.substr(0, posAndDef.find(" -"));
                def = posAndDef.erase(0, posAndDef.find(" -") + 6);
                defcounter++;
                def = reWriterSorter(def);

                myVec.push_back(make_pair(word, make_pair(pos, def)));
            }
        }
        sort(myVec.begin(), myVec.end()); //sorts alphabetically.
        cout << "! Loading completed...\n";
    }
    FileReader.close();
    cout << endl << "====== DICTIONARY 340 C++ =====" << endl;
    cout << "------ Keywords: " << wordcounter << endl;
    cout << "------ Definitions: " << defcounter << endl;
}

// reWriterSorter It will capitalize first letter of word
string reWriterSorter(string str) {
    // if word has number in it, capitalize it
    for (int i = 0; i < str.size(); i++)
        if (isdigit(str[i])) {
            for (int j = 0; j < str.size(); j++) {
                str[j] = toupper(str[j]);

            }
        }
    str[0] = toupper(str[0]);
    return str;
}

// reWriterInput will make sure input is reformatted properly for search
string reWriterInput(string str) {
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    str[0] = toupper(str[0]);

    for (int i = 0; i < str.size(); i++)
        if (isdigit(str[i])) {
            //int untilspace =0;
            int untilspace = str.find(" ");
            if (untilspace == -1) { //if it doesnt find sapce, it uppers whole size
                for (int j = 0; j < str.size(); j++) {
                    str[j] = toupper(str[j]);
                }
            } else { //if it finds space, it uppers only the word
                for (int j = 0; j < untilspace; j++) {
                    str[j] = toupper(str[j]);
                }
            }
        }
    return str;
}
