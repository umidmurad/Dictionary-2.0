//
// Created by Umid Muradli on 2/23/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
        string line;
        fstream FileReader;
        vector<string> startingvector;
        FileReader.open("/Users/umidmuradli/Documents/GitHub/Dictionary-2.0/Data.CS.SFSU.txt", ios::in);
        if (FileReader.is_open()){
            while (!FileReader.eof()){
                while(getline(FileReader, line))
                {
                    //reads def,
                    string tokend;
                    string del = "-=>>";
                    string dels = "|";
                    size_t pos = line.find(del);
                    size_t space = line.find(dels);
                    tokend = line.substr(pos+5, space);
                    startingvector.push_back(tokend);
                }


            }
        }
        else
        { //if cant open the file
            cout <<"Error opening the file.";
        }
        FileReader.close();
        for ( int i = 0; i < startingvector.size(); i++)
        {cout << startingvector[i] <<endl;}

//    //this works for getting speech
//    string token;
//    string del = "|";
//    size_t pos = line.find(del);
//    size_t space = line.find(' ');
//    token = line.substr(pos+1, space-pos);
//    startingvector.push_back(token);

// //reads words,
//    string tokenw;
//    string del = "|";
//    size_t pos = line.find(del);
//    //size_t space = line.find(' ');
//    tokenw = line.substr(0, pos);
//    startingvector.push_back(tokenw);
    return 0;
};