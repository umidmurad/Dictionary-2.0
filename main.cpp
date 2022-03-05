#include <iostream>
#include <string>
#include "Printer.cpp"
using namespace std;

int main() {
    FileLoader(); //loads the data
    filler(); // loads available options (reverse, distinct, all pos)
    string input;
    int keepCount =1;
    while(true) {
        cout << "\nSearch [" <<keepCount <<"] : ";
        keepCount++;
        getline(cin, input);
        if(input ==" " || input =="" || input =="!help") {guidePrinter();continue;}
        else if(input=="!q" || input == "!Q") {cout <<"\n-----THANK YOU-----\n"; return 0;}
        input = reWriterInput(input);//we make sure users input matches word in vector before passing it to handler
        handler(inputSep(input));
    }
}
