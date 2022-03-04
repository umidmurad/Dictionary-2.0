//
// Created by Umid Muradli on 3/1/22.
//
#include "Fileloader.cpp"

void wordPrinter(vector<pair<string, pair<string, string>>> );
vector<string> inputSep(string);
vector<pair<string,pair<string,string>>> lookUp(string );
vector<pair<string,pair<string,string>>>  distinctHelper(vector<string>);
vector<pair<string,pair<string,string>>>  reverseHelper(vector<string> optionHolder);
void filler();
void errorChecker(string, int);
void notAvailable();
bool existOrNot(string, vector<string>);
void handler(vector<string>);
void guidePrinter();
vector<pair<string,pair<string,string>>> specificWordGetter(vector<string>, vector<pair<string,pair<string,string>>>);
vector<pair<string, pair<string, string> > > tempVec;
vector<string> spchType2;


void filler() {
    spchType2.push_back("verb");
    spchType2.push_back("noun");
    spchType2.push_back("adjective");
    spchType2.push_back("adverb");
    spchType2.push_back("conjunction");
    spchType2.push_back("interjection");
    spchType2.push_back("preposition");
    spchType2.push_back("pronoun");
    spchType2.push_back("reverse");
    spchType2.push_back("distinct");
}

vector<string> inputSep(string input) {
    input.push_back(' '); // If I do not add a space, it will not read the last thing inputted
    vector<string> optionHolder;
    stringstream line(input);
    string option;
    size_t numberOfSpaces = count(input.begin(), input.end(), ' ');
    for (size_t i = 0; i < numberOfSpaces; i++) {
        getline(line, option, ' ');
        if (option == "") // If Extra Space is inputted skip to next word
            continue;
        optionHolder.push_back(option);
    }
    return optionHolder;
}

void handler(vector<string> optionHolder) {
    tempVec = specificWordGetter(optionHolder, myVec);
    if(tempVec.empty()) return;
    if (optionHolder.size() >= 2) {
        for (int i = 2; i <= optionHolder.size(); ++i) {
            switch (i) {
                case 1: break;
                case 2:
                    if (optionHolder[1] == "distinct")
                        tempVec = distinctHelper(optionHolder);
                    else if (optionHolder[1] == "reverse")
                        tempVec = reverseHelper(optionHolder);
                    else
                        tempVec = lookUp(optionHolder[1]);
                    break;
                case 3: //book noun ok
                    if (optionHolder[2] == "distinct")
                        tempVec = distinctHelper(optionHolder);
                    else if (optionHolder[2] == "reverse")
                        tempVec = reverseHelper(optionHolder);
                    else errorChecker(optionHolder[2], 3);
                    break;
                case 4:
                    if (optionHolder[3] == "reverse")
                        tempVec = reverseHelper(optionHolder);
                    else errorChecker(optionHolder[3], 4);
                    break;
                default: guidePrinter(); return;
            }
        }
    }

    if(tempVec.empty() && (existOrNot(optionHolder[1], spchType2)) )
    {guidePrinter(); return;}
    else if(tempVec.empty())
        tempVec = specificWordGetter(optionHolder, myVec);
    wordPrinter(tempVec);
    tempVec.clear();
}

vector<pair<string,pair<string,string>>> specificWordGetter(vector<string> optionHolder, vector<pair<string,pair<string,string>>> vec){
    vector<pair<string,pair<string,string>>> temp;
    for(pair<string,pair<string,string>> value: vec)
        if(value.first == optionHolder[0]) //
            temp.push_back(value);
    if(temp.empty()) {
        notAvailable();
        guidePrinter();
    }
    return temp;
}

void wordPrinter(vector<pair<string, pair<string, string>>> tempVec) {
    cout << "\t|" << endl;
    for (int i = 0; i < tempVec.size(); i++) {
            cout << "\t " << tempVec[i].first << " [" << tempVec[i].second.first
                 << "]  : " << tempVec[i].second.second << endl;
    }
    cout << "\t|";
}

vector<pair<string,pair<string,string>>> lookUp(string pos) {
    for (int i = 0; i < tempVec.size(); i++) {
        if(!(pos == tempVec[i].second.first)){
            tempVec.erase(tempVec.begin() + i);
        i--;
        }
    }

    if (tempVec.empty() and !existOrNot(pos, spchType2)) // book ok
        errorChecker(pos, 2);
    else if(tempVec.empty() and existOrNot(pos, spchType2))
            notAvailable();
return tempVec;
}
//___________________________________________________
//DISTINCT
vector<pair<string,pair<string,string>>>  distinctHelper(vector<string> optionHolder) {
    if(tempVec.size() == 0)
        tempVec = specificWordGetter(optionHolder, myVec);
    int j = 0;
    if (tempVec.size() > 1) {
        for (int i = 1; i < tempVec.size(); i++) {
            if ((tempVec[j].first == tempVec[i].first) && (tempVec[j].second.first == tempVec[i].second.first) &&
                (tempVec[j].second.second == tempVec[i].second.second)) {
                tempVec.erase(tempVec.begin() + j);
                i--;
                continue;
            }
            j++;
        }
    }
return tempVec;
}
//REVERSE
vector<pair<string,pair<string,string>>>  reverseHelper(vector<string> optionHolder) {
    if(tempVec.size() == 0)
        tempVec = specificWordGetter(optionHolder, myVec);
    reverse(tempVec.begin(), tempVec.end());
return tempVec;
}
//___________________________________________________
void errorChecker(string input, int caseNumber) {
    switch (caseNumber) {
        case 2:
            cout << "\t|\n\t <The entered " << caseNumber << "nd parameter '" << input << "' is NOT a part of speech.>"
                 << endl;
            cout << "\t <The entered " << caseNumber << "nd parameter '" << input << "' is NOT 'distinct'.>" << endl;
            cout << "\t <The entered " << caseNumber << "nd parameter '" << input << "' is NOT 'reverse'.>" << endl;
            cout << "\t <The entered " << caseNumber << "nd parameter '" << input << "' was disregarded.>" << endl;
            cout << "\t <The " << caseNumber << "nd parameter should be a part of speech or 'distinct' or 'reverse'.>"
                 << endl << "\t|" << endl;
            break;
        case 3:
            cout << "\t|\n\t <The entered " << caseNumber << "rd parameter '" << input << "' is NOT 'distinct'.>" << endl;
            cout << "\t <The entered " << caseNumber << "rd parameter '" << input << "' is NOT 'reverse'.>" << endl;
            cout << "\t <The entered " << caseNumber << "rd parameter '" << input << "' was disregarded.>" << endl;
            cout << "\t <The " << caseNumber << "rd parameter should be 'distinct' or 'reverse'.>" << endl << "\t|" << endl;
            break;
        case 4:
            cout << "\t|\n\t <The entered " << caseNumber << "th parameter '" << input << "' is NOT 'reverse'.>" << endl;
            cout << "\t <The entered " << caseNumber << "th parameter '" << input << "' was disregarded.>" << endl;
            cout << "\t <The " << caseNumber << "th parameter should be 'reverse'.>" << endl << "\t|" << endl;
            break;
    }
}

bool existOrNot(string input, vector<string> listToCheck) {
    for (string option: listToCheck)
        if (option == input)
            return true;
    return false;
}

void notAvailable() {
    cout << "\t|\n \t <NOT FOUND> To be considered for the next release. Thank you." << endl;

}
void guidePrinter(){
        string guide = "\t|\n \t PARAMETER HOW-TO, please enter:\n\t 1. A search key -then 2. An optional part of speech -then\n\t 3. An optional 'distinct' -then 4. An optional 'reverse'\n \t|";
        cout << guide;
    }

