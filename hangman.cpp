//
//  main.cpp
//  hangman
//
//  Created by Jean Tu during the Fall of 2015
//  Copyright (c) 2015 Jean Tu. All rights reserved.
//

#include <iostream>
#include <cstdlib> 
#include <string> 
#include <sstream> 
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <vector> 
#include <map> 
#include <stdlib.h>     /* srand, rand */
#include <time.h> /* to seed the random */
#include <set> /* to store the already guessed characters */

using namespace std; 

int main(int argc, const char * argv[]) {
    if(argc < 2) {
        cout << "Enter the file name you would like to read in from" << endl;        cout << "Try again with ./hangman <input.txt>" << endl;
        return -1; //break out of the program 
    }
    ifstream ifile(argv[1]); //takes in the file name of the words
    string buffer = "";
    //this will be the word bank and a word will randomly be choosen
    map<string, string> bank; 
    string topic = ""; //the topic that the words can be on
    //getting the words from the file and adding them to the vector 
    getline(ifile, buffer); 
    stringstream ss(buffer); 
    ss >> topic; 
    vector<string> randomlyGWord; //stores the word to be able to find them in the map 
    string key = ""; 
    string value = ""; 
    while(getline(ifile, buffer)){
        stringstream ss(buffer);
        string temp = "";        
        ss >> temp; 
        for(unsigned int i = 0; i < temp.length(); i++) {
            temp[i] = tolower(temp[i]); //lowers it so that it would be searchable
        }
        key = temp; 
        while(ss >> temp) {
            value = value + " " + temp; 
        }        
        //make the pair & add it to the map 
        bank[key] = value;
        randomlyGWord.push_back(key); 
        //reseting the values 
        value = ""; 
        key = "";  
    }
    int size = randomlyGWord.size(); //limit for the number generator to get a word
    //selecting a random word in the vector
    srand (time(NULL));
    int random = rand() % size;
    int guesses = randomlyGWord[random].size(); 
    string word = randomlyGWord[random];
    string hint = bank[word]; 
    bool giveUp = false; 
    bool letterFound = false; 
    string good; 
    cout << "Guesses to start off with: " << guesses << endl;
    cout << "   ";
    for(unsigned int i= 0; i < word.size(); i++){ //the outline of the word
        cout << "*" ;
        good += "*";  
    }
    cout << endl; 
    cout << "TOPIC: " << topic << endl;
    cout << "HINT: " << hint << endl;

    cout << "   Please enter one character at a time to guess the letters" << endl;
    cout << "   Or enter 1 to quit/give up" << endl;
    char c; 
    string guess;
    set<char> guessedBank;
    set<char> alreadyGuessed;
    bool nextGuess = false; //if the user haas already guessed that letter, it should move on and skip the else statement in the while clause

    cin >> guess; 
    int correct = 0; 
    //grabs only the first character, if the user enters anything larger than 1
    if(guess.size() >= 1){
        c = guess[0];
    }
    //while they still have guesses left or still have letters to guess 
    while(guesses > 0 && c != 1){
        letterFound = false;
        nextGuess = false; 
        for(set<char>::iterator it = alreadyGuessed.begin(); it != alreadyGuessed.end();++it){
            if(*it == c){
                cout << "You've already guessed " << c << endl; 
                nextGuess = true;  
            }
        }
        if(c == '1'){
            //gave up & show them the word 
            cout << "The word was: " << word << endl;
            giveUp = true; 
            break;
        }
        if(c == '2'){
            cout << "THE HINT IS: " << hint << endl;
        }
        else if(nextGuess == false) {
            for(unsigned int i =0; i < word.size(); i++){
                if(word[i] == c){
                    letterFound = true;
                    good[i] = c;
                    correct++;
                    alreadyGuessed.insert(c); 
                }
                //do nothing for else case
            }//end of for loop 
            if(letterFound == false){// && guesses > 0) {
                //add the letter to the wrong bank 
                guessedBank.insert(c);
                guesses--; //subtract one 
                if(guesses == 0){
                    cout << "Sorry, you ran out of tries. The right word was: " << randomlyGWord[random] << endl;
                    return 0; 
                }       
            }
            else {
                cout << "   CORRECT: you've guessed a letter! " << endl;
            }
            cout << endl;
        } 
        cout << "   " << good << endl; //prints out the word so the user can see what they have solved
        if(good == word){
            cout << endl; 
            cout << "CONGRATULATIONS! You've solved the word!!!" << endl;
            return 0;
        }
        cout << "GUESSES LEFT: " << guesses << endl;
        cout << "----------------------------------------------" << endl;
        cout << "|   INCORRECT letters you guessed:           "<< endl;
        cout << "|   "; 
        for(set<char>::iterator it = guessedBank.begin(); it != guessedBank.end();++it){
            cout << *it << " ";
        }
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "--------Guess again, enter 1 to quit/give up, or 2 to see the HINT again-------" << endl;
        cin >> c;
        letterFound = false;  
    }
    if(guesses == 0){
        cout << "Sorry, you ran out of tries. The right word was: " << randomlyGWord[random] << endl;
        return 0; 
    }
    if(giveUp == false){
        cout << "The word was: " << word << endl;
    }
              
    cout << endl;

    return 0;
}
