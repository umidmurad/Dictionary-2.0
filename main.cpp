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
    //new after this
    string input;
    int keepcount =1;
    while(input != "!q") {
        cout << "\n\nSearch [" <<keepcount <<"] : ";
        keepcount++;
        getline(cin, input);
        input = reWriterInput(input);
        cout <<"\n|";
        //caseChooser(input);
        inputSep(input);
        cout <<"\n|";
    }
    return 0;
}
