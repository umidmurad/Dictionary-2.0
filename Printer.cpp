//
// Created by Umid Muradli on 3/1/22.
//

bool wordprinter(string);
void inputSep(string);
void posprinter(vector<string>);
void filler();
void errorChecker();
void notAvailable();
vector<string> spchType2;
vector<string> distinct3;
vector<string> reverse4;

void errorChecker(string input, int caseNumber){
    switch (caseNumber) {
        case 2: cout << "<The entered" << caseNumber << "nd parameter'" << input << " is NOT a part of speech.>" << endl;
        cout << "<The entered " << caseNumber << "nd parameter '" + input << "' is NOT 'distinct'.>" << endl;
        cout << "<The entered " << caseNumber << "nd parameter '" << input << "' is NOT 'reverse'.>" << endl;
        cout << "<The entered " << caseNumber << "nd parameter '" << input << "' was disregarded.>" << endl;
        cout << "<The " << caseNumber <<"nd parameter should be a part of speech or 'distinct' or 'reverse'.>" << endl << "|" << endl;
            break;
        case 3: cout << "<The entered " << caseNumber << "nd parameter '" + input << "' is NOT 'distinct'.>" << endl;
            cout << "<The entered " << caseNumber << "nd parameter '" << input << "' is NOT 'reverse'.>" << endl;
            cout << "<The entered " << caseNumber << "nd parameter '" << input << "' was disregarded.>" << endl;
            cout << "<The " << caseNumber <<"nd parameter should be 'distinct' or 'reverse'.>" << endl << "|" << endl;
            break;
        case 4: cout << "<The entered " << caseNumber << "nd parameter '" << input << "' is NOT 'reverse'.>" << endl;
            cout << "<The entered " << caseNumber << "nd parameter '" << input << "' was disregarded.>" << endl;
            cout << "<The " << caseNumber <<"nd parameter should be 'reverse'.>" << endl << "|" << endl;
            break;
    }
}
void filler(){
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

void inputSep(string input){
    vector<string> optionHolder; //declare new vector
    string temp = input, option; //temp holds the input
    input.append(" "); // If I do not add a space, it will not read the last thing inputted
    stringstream line(input);
    int numberOfSpaces = count(input.begin(), input.end(), ' ');
    for(int i = 0; i < numberOfSpaces; i++) {
        getline(line, option, ' ');
        if (option == "") // If Extra Space is inputted skip to next word
            continue;
        optionHolder.push_back(option);
    }
    switch (numberOfSpaces) {
        case 1: wordprinter(temp); break;
        case 2: posprinter(optionHolder); break;
        case 3: cout << "distinct, reverse" << endl; break;
        case 4: cout << "reverse" << endl; break;
        default: cout << "You have inputted more than 4 options" << endl;
    }
}

bool wordprinter(string input){
    //we need error function when word doesn't exist.
    bool check = false;
    for (int i = 0; i < myvec.size(); i++) {
        if (input == myvec[i].first) {
            cout << myvec[i].first << " [" << myvec[i].second.first
                  << "]  : " << myvec[i].second.second<< endl;
            check =true;
        }
    }cout << "|";
    if(!check) notAvailable();
 return check;
}
void notAvailable(){
    cout <<"<NOT FOUND> To be considered for the next release. Thank you.\n|";
}
bool existOrNot(string input, vector<string> listToCheck){
    for(string option: listToCheck)
        if (option == input)
            return true;
    return false;
}
void posprinter(vector<string> optionHolder)
{       //this function needs another function to check if the pos actually is not random word.
    bool check= true;
    for (int i = 0; i < myvec.size(); i++) {
        if (optionHolder[0] == myvec[i].first && optionHolder[1] ==myvec[i].second.first) {
            cout<< myvec[i].first << " [" << myvec[i].second.first
                  << "]  : " << myvec[i].second.second << endl;
            check = false;
        }

    }
    cout<< "|";
    if(!check) return;
    if(!existOrNot(optionHolder[1], spchType2)) // if word is not in the list spchType2
        errorChecker(optionHolder[1], 2);
    if (!wordprinter(optionHolder[0])) // if word is not not in txt file
        notAvailable();


    cout << "|" << endl;
    //if(check){
        //errorChecker(optionHolder[1],2); // 2 means, pos is wrong input
   // } //checks if function exists
}





//vector<string> inputSep(string input){
//    input.append(" "); // If I do not add a space, it will not read the last thing inputted
//    vector<string> optionHolder;
//    stringstream line(input);
//    string option;
//    size_t numberOfSpaces = count(input.begin(), input.end(), ' ');
//    for(size_t i = 0; i < numberOfSpaces; i++) {
//        getline(line, option, ' ');
//        if(option == "") // If Extra Space is inputted skip to next word
//            continue;
//        optionHolder.push_back(option);
//    }
//    /*for(string temp : optionHolder)
//        cout << temp << endl;*/
//return optionHolder;
//}


//void caseChooser(string input, ){
//    vector<string> optionHolder = inputSep(input);
//    //vector<string> optionHolder = inputSep(input);
//    switch (optionHolder.size()) {
//        case 1: wordprinter(input); break;
//        case 2: cout << "print lookUp, distinct, reverse" << endl; break;
//        case 3: cout << "distinct, reverse" << endl; break;
//        case 4: cout << "reverse" << endl; break;
//        default: cout << "You have inputted more than 4 options" << endl;
//    }
//}
