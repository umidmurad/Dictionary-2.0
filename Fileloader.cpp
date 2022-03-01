//
// Created by Umid Muradli on 2/27/22.
//

#include <iostream>
#include <fstream>
#include "sstream"
#include <vector>
#include "algorithm"

using namespace std;
string reWriterSorter(string);
string reWriterInput(string);
void wordprinter(string);
void inputSep(string);
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

void inputSep(string input){
    string temp = input;
    input.append(" "); // If I do not add a space, it will not read the last thing inputted
    stringstream line(input);
    int numberOfSpaces = count(input.begin(), input.end(), ' ');
    switch (numberOfSpaces) {
        case 1: wordprinter(temp); break;
        case 2: cout << "print lookUp, distinct, reverse" << endl; break;
        case 3: cout << "distinct, reverse" << endl; break;
        case 4: cout << "reverse" << endl; break;
        default: cout << "You have inputted more than 4 options" << endl;
    }
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
void wordprinter(string input){
    //we need error function when word doesn't exist.
        for (int i = 0; i < myvec.size(); i++) {
            while (input == myvec[i].first) {
//            if (myvec[i].first == input) {
                cout  <<endl << myvec[i].first << " [" << myvec[i].second.first
                << "]  : " << myvec[i].second.second  ;
                i++;
            }
        }
}

//vector<string> inputSep(string input){
//    input.append(" "); // If I do not add a space, it will not read the last thing inputted
//    vector<string> optionHolder;
//    stringstream line(input);
//    string option;
//    size_t numberOfSpaces = count(input.begin(), input.end(), ' ');
//    for(size_t i = 0; i < numberOfSpaces; i++) {
//        getline(line, option, ' ');
//        if(option == "") // If Extra Space is inputted skip to next word
//            continue;
//        optionHolder.push_back(option);
//    }
//    /*for(string temp : optionHolder)
//        cout << temp << endl;*/
//return optionHolder;
//}


//void caseChooser(string input, ){
//    vector<string> optionHolder = inputSep(input);
//    //vector<string> optionHolder = inputSep(input);
//    switch (optionHolder.size()) {
//        case 1: wordprinter(input); break;
//        case 2: cout << "print lookUp, distinct, reverse" << endl; break;
//        case 3: cout << "distinct, reverse" << endl; break;
//        case 4: cout << "reverse" << endl; break;
//        default: cout << "You have inputted more than 4 options" << endl;
//    }
//}