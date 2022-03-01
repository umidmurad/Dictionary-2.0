// Created by Umid Muradli on 2/23/22.
//
#include <iostream>
#include <string>
#include "algorithm"
#include "Fileloader.cpp"
#include "Printer.cpp"
using namespace std;

int main() {
    FileLoader(); //loads the data
    filler();
    //new after this
    string input;
    int keepcount =1;
    while(input != "!q") {
        cout << "\nSearch [" <<keepcount <<"] : ";
        keepcount++;
        getline(cin, input);
        cout << "|"<< endl;
        input = reWriterInput(input);
        //caseChooser(input);
        inputSep(input);
    }
    return 0;
}
