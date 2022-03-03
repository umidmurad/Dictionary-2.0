//
// Created by Umid Muradli on 3/1/22.
//

void wordprinter(string);

vector<string> inputSep(string);

void caseChooser(string input);

void posprinter(vector<string>);

void distincthelper(vector<string>);

void reversehelper(vector<string>);

void filler();

void errorChecker(string, int);

void notAvailable();

bool existOrNot(string, vector<string>);

void handler(vector<string>);

vector<pair<string, pair<string, string> > > tempvec;
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


void caseChooser(string input) {
    vector<string> optionHolder = inputSep(input);
    switch (optionHolder.size()) {
        case 1:
            wordprinter(input);
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
}


void wordprinter(string input) {
    //we need error function when word doesn't exist.
    bool check = false;
    cout << "|" << endl;
    for (int i = 0; i < myvec.size(); i++) {
        if (input == myvec[i].first) {
            cout << " " << myvec[i].first << " [" << myvec[i].second.first
                 << "]  : " << myvec[i].second.second << endl;
            check = true;
        }
    }
    if (!check) notAvailable(); // if word not printed (check = false), not Available is called
    cout << "|\n";
}


//existOrNot can be reused for reverse and distinct key option
// in the case of: Book noun reverse, do: existOrNot(input *which holds reverse* , *whatever list you want to check if
// input exists in, for third position do distinct3*)


void posprinter(
        vector<string> optionHolder) {       //this function needs another function to check if the pos actually is not random word.
    bool check = true;
    cout << "|\n";

    for (int i = 0; i < myvec.size(); i++) {
        if (optionHolder[0] == myvec[i].first && optionHolder[1] == myvec[i].second.first) {
            cout << " " << myvec[i].first << " [" << myvec[i].second.first
                 << "]  : " << myvec[i].second.second << endl;
            check = false;
        }

    }
    // if the word and pos was founded and printed, do not try to check for errors (line 114-116), just return back to main

    if (!check) {
        cout << "|";
        return;
    }// if the word and pos was founded and printed, do not try to check for errors (line 114-116), just return back to main
    if (!existOrNot(optionHolder[1], spchType2)) // if input is not in the list spchType2
        errorChecker(optionHolder[1], 2); // 2 is for second position is invalid.
    wordprinter(optionHolder[0]); // wordPrinter will attempt to print word, if not in txt file, it calls notAvailable()
}


//___________________________________________________
//DISTINCT
void distincthelper(vector<string> optionHolder) {
    vector<pair<string, pair<string, string> > > tempvec = myvec;
    int j = 0;
    if (tempvec.size() > 1) {
        for (int i = 1; i < tempvec.size(); i++) {
            if ((tempvec[j].first == tempvec[i].first) && (tempvec[j].second.first == tempvec[i].second.first) &&
                (tempvec[j].second.second == tempvec[i].second.second)) {
                tempvec.erase(tempvec.begin() + j);
                i--;
                continue;
            }
            j++;
        }
    }

    for (int i = 0; i < tempvec.size(); i++) {
        if (optionHolder[0] == tempvec[i].first) {
            cout << " " << tempvec[i].first << " [" << tempvec[i].second.first
                 << "]  : " << tempvec[i].second.second << endl;

        }
    }
}

//REVERSE
void reversehelper(vector<string> optionHolder) {
    vector<pair<string, pair<string, string> > > tempvec = myvec;
    reverse(tempvec.begin(), tempvec.end());
    for (int i = 0; i < tempvec.size(); i++) {
        if (optionHolder[0] == tempvec[i].first) {
            cout << " " << tempvec[i].first << " [" << tempvec[i].second.first
                 << "]  : " << tempvec[i].second.second << endl;

        }
    }
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

void handler(vector<string> optionHolder) {
    switch (optionHolder.size()) {
            case 2:
                if (optionHolder[1] == "distinct")
                    distincthelper(optionHolder);
                else if (optionHolder[1] == "reverse")
                    reversehelper(optionHolder);
                else
                    posprinter(optionHolder);
                break;
            case 3:
                if (optionHolder[2] == "distinct")
                    distincthelper(optionHolder);
                else if (optionHolder[2] == "reverse")
                    reversehelper(optionHolder);
                break;
            case 4: if(optionHolder[3] == "reverse")
                    reversehelper(optionHolder);
                break;

    }
}
