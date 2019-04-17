/*
Purpose: To take in a list of words to give to the hash class
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.0.0
Date of Creation: 4/16/2019
Date of Last Revision: 4/16/2019
*/
#include <iostream>
#include <string>
#include "myHash.h"

using namespace std;

int main()
{
    int words = 0;
    string name;


    while(words <= 15){
        cout<<"Input name to be stored in the hash: ";
        cin>>name;
        myHash.store(name);
        words++;
    }

    cout<<"Contents of hash: "<<myHash.display()<<endl;

    while(name != "n"){
        cout<<"Input name to search for or input 'n' to quit";
        cin>>name;

        if(name != 'n'){
            myHash.whereis(name);
        }
    }

    return 0;
}
