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
    int keepCount =1;
    while(true) {
        cout << "\nSearch [" <<keepCount <<"] : ";
        keepCount++;
        getline(cin, input);
        if(input ==" " || input =="" || input =="!help") {guidePrinter();continue;}
        else if(input=="!q" || input == "!Q") {cout <<"\n-----THANK YOU-----\n"; return 0;}
        input = reWriterInput(input);
        handler(inputSep(input));
    }
    return 0;
}
