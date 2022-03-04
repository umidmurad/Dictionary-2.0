// Created by Umid Muradli on 2/23/22.
//
#include <iostream>
#include <string>
#include <cctype>
#include "algorithm"
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
        input = reWriterInput(input);
        handler(inputSep(input));
    }
    return 0;
}
