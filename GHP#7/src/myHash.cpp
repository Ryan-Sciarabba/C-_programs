/*
Purpose: To take in a list of words to store, search for, and display
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.0.0
Date of Creation: 4/16/2019
Date of Last Revision: 4/16/2019
*/
#include "myHash.h"
#include <vector>
#include <string>

using namespace std;

myHash::myHash(){
    vHash.insert(vHash.begin(), 23, "??");
}

void myHash::store(string &word){

    mpty = false;

    slot = ((int(word[0])) + (int(word.size() - 1))) % 23;

    while(mpty == false){
        if(vHash[slot] == "??"){
            vHash.insert(vHash[slot], 1, word);
            mpty == true;
        }
        else{
            slot++;
        }
}

void myHash::whereIs(string &word){

    found = false;

    slot = ((int(word[0])) + (int(word.size() - 1))) % 23;

    while(found == false){
        if(vHash[slot] == word){
            cout<<word<<" was found at position "<<slot<<endl;
            found = true;
        }
        else{
            slot++;
        }
    }
}

void myHash::display(){
    for(i = 0; i <= (vhash.size() - 1); i++){
        cout<<endl<<"Position "<<i<<": "<<vHash[i]<<endl;
    }
}

