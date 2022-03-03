//
// Created by Umid Muradli on 3/1/22.
//
#include "Fileloader.cpp"

void wordPrinter(string);

vector<string> inputSep(string);

void caseChooser(string input);

vector<pair<string,pair<string,string>>> posPrinter(vector<string>);

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
vector<string> distinct3;
vector<string> reverse4;


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
    distinct3.push_back("distinct");
    distinct3.push_back("reverse");
    reverse4.push_back("reverse");
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
//Function that checks


/*void caseChooser(string input) {
    vector<string> optionHolder = inputSep(input);
    switch (optionHolder.size()) {
        case 1:
            wordPrinter(input);
            break;
        case 2:
            handler(optionHolder);
            break;
        case 3:
            handler(optionHolder);
            break;
        case 4:
            handler(optionHolder);
            break;
        default:
            cout << "You have inputted more than 4 options" << endl;
    }
}*/


void wordPrinter(vector<pair<string, pair<string, string>>> tempVec) {
    cout << "|" << endl;
    for (int i = 0; i < tempVec.size(); i++) {
            cout << " " << tempVec[i].first << " [" << tempVec[i].second.first
                 << "]  : " << tempVec[i].second.second << endl;
    }
    if (tempVec.empty()) notAvailable();
    cout << "|\n";
}

vector<pair<string,pair<string,string>>> specificWordGetter(vector<string> optionHolder, vector<pair<string,pair<string,string>>> vec){
    vector<pair<string,pair<string,string>>> temp;
    for(pair<string,pair<string,string>> value: vec)
        if(value.first == optionHolder[0]) //
            temp.push_back(value);
    return temp;
}

vector<pair<string,pair<string,string>>> posPrinter(string pos) {
    for (int i = 0; i < tempVec.size(); i++) {
        if(!(pos == tempVec[i].second.first)){
            tempVec.erase(tempVec.begin() + i);
        i--;
        }

    }
    if(tempVec.empty() and existOrNot(pos, spchType2))
        notAvailable();
    else if (tempVec.empty())
        errorChecker(pos, 2);
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
            cout << " <The entered " << caseNumber << "nd parameter '" << input << "' is NOT a part of speech.>"
                 << endl;
            cout << " <The entered " << caseNumber << "nd parameter '" + input << "' is NOT 'distinct'.>" << endl;
            cout << " <The entered " << caseNumber << "nd parameter '" << input << "' is NOT 'reverse'.>" << endl;
            cout << " <The entered " << caseNumber << "nd parameter '" << input << "' was disregarded.>" << endl;
            cout << " <The " << caseNumber << "nd parameter should be a part of speech or 'distinct' or 'reverse'.>"
                 << endl << "|" << endl;
            break;
        case 3:
            cout << " <The entered " << caseNumber << "nd parameter '" + input << "' is NOT 'distinct'.>" << endl;
            cout << " <The entered " << caseNumber << "nd parameter '" << input << "' is NOT 'reverse'.>" << endl;
            cout << " <The entered " << caseNumber << "nd parameter '" << input << "' was disregarded.>" << endl;
            cout << "<The " << caseNumber << "nd parameter should be 'distinct' or 'reverse'.>" << endl << "|" << endl;
            break;
        case 4:
            cout << " <The entered " << caseNumber << "nd parameter '" << input << "' is NOT 'reverse'.>" << endl;
            cout << " <The entered " << caseNumber << "nd parameter '" << input << "' was disregarded.>" << endl;
            cout << " <The " << caseNumber << "nd parameter should be 'reverse'.>" << endl << "|" << endl;
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
    cout << " <NOT FOUND> To be considered for the next release. Thank you." << endl;
}
void guidePrinter(){
        string guide = "\t|\n \t PARAMETER HOW-TO, please enter:\n\t 1. A search key -then 2. An optional part of speech -then\n\t 3. An optional 'distinct' -then 4. An optional 'reverse'\n \t|";
        cout << guide;
    }

void handler(vector<string> optionHolder) {
    tempVec = specificWordGetter(optionHolder, myVec);
    /*cout << tempVec[0].second.second << endl;
    cout << tempVec[1].second.second << endl;
    cout << tempVec[2].second.second << endl;
    cout << tempVec[3].second.second << endl;*/
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
                        tempVec = posPrinter(optionHolder[1]);
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
                default: guidePrinter();
            }
        }
    }
    if(tempVec.size() == 0)
        tempVec = specificWordGetter(optionHolder, myVec);
    wordPrinter(tempVec);
    tempVec.clear();
}
