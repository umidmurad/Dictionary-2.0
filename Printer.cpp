//
// Created by Umid Muradli on 3/1/22.
//

void wordprinter(string);
void inputSep(string);
void posprinter(vector<string>);
void inputSep(string input){
    vector<string> optionHolder; //declare new vector
    string temp = input, option; //temp holds the input
    input.append(" "); // If I do not add a space, it will not read the last thing inputted
    stringstream line(input);
    int numberOfSpaces = count(input.begin(), input.end(), ' ');
    for(int i = 0; i < numberOfSpaces; i++) {
        getline(line, option, ' ');
        if(option == "") // If Extra Space is inputted skip to next word
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

void wordprinter(string input){
    //we need error function when word doesn't exist.
    bool check =true;
    for (int i = 0; i < myvec.size(); i++) {
        if (input == myvec[i].first) {
            cout  <<endl << myvec[i].first << " [" << myvec[i].second.first
                  << "]  : " << myvec[i].second.second;
            check =false;
        }
    }
    if(check){cout <<endl << input << " not found";} //checks if function exists
}

void posprinter(vector<string> optionHolder)
{       //this function needs another function to check if the pos actually is not random word.
    bool check= true;
    for (int i = 0; i < myvec.size(); i++) {
        if (optionHolder[0] == myvec[i].first && optionHolder[1] ==myvec[i].second.first) {
            cout  <<endl << myvec[i].first << " [" << myvec[i].second.first
                  << "]  : " << myvec[i].second.second;
            check =false;
        }
    }
    if(check){cout <<endl  << "<Not found> To be considered for next release";} //checks if function exists
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
