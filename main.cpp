// Created by Umid Muradli on 2/23/22.
//
#include <iostream>
#include <string>
#include "algorithm"
#include "Fileloader.cpp"
using namespace std;

int main() {
    FileLoader(); //loads the data
    //new after this
    string input;
    while(input != "!q") {
        cout << "\n\nType something here:   ";
        cin >> input;
        input = reWriterInput(input);
        cout <<"\n|";
        for (int i = 0; i < myvec.size(); i++) {

            while (input == myvec[i].first) {

                cout  <<endl << myvec[i].first << " [" << myvec[i].second.first
                     << "]  : " << myvec[i].second.second  ;
                i++;
            }
        }
        cout <<"\n|";
    }
    return 0;
}
