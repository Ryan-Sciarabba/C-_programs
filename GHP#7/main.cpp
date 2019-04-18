/*
Purpose: To take in a list of words to give to the hash class
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.4e.2
Date of Creation: 4/16/2019
Date of Last Revision: 4/16/2019
*/
#include <iostream>
#include <string>
#include "myHash.h"

using namespace std;

int main()
{
    myHash aHash; //Create hash
    int words = 1; //Number of names input
    string name; //Name to be input

    //Have user input 15 names and store them in the hash
    while(words <= 15){
        cout<<"Input name to be stored in the hash: ";
        cin>>name;
        aHash.store(name);
        words++;
    }

    //Print out hash
    cout<<"Contents of hash: ";
    aHash.display();
    cout<<endl;

    //Have user search for names in the hash
    while(name != "@"){
        cout<<"Input name to search for or input '@' to quit: ";
        cin>>name;

        if(name != "@"){
            aHash.whereIs(name);
        }
    }

    return 0;
}
