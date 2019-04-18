/*
Purpose: To take in a list of words to store, search for, and display
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 2.2.4
Date of Creation: 4/17/2019
Date of Last Revision: 4/18/2019
*/

#include <iostream>
#include "myHash.h"
#include <vector>
#include <string>

using namespace std;

myHash::myHash(){

    //Fill hash with question marks
    vHash.insert(vHash.begin(), 23, "??");
}

/*
Purpose: To store words in a hash
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 2.2.6
Date of Creation: 4/17/2019
Date of Last Revision: 4/18/2019
*/
void myHash::store(string &word){

    //Slot status is unknown
    mpty = false;

    //Figure out the slot to put the name into
    slot = ((int(word[0])) + (int(word[word.size() - 1]))) % 23;

    //Check to see if slot is empty and if not move up one slot. Repeat
    while(mpty == false){
        if(vHash[slot] == "??"){
            vHash.erase(vHash.begin() + slot);
            vHash.insert(vHash.begin() + slot, 1, word);
            mpty = true;
        }
        else{
            slot++;
        }
    }
}

/*
Purpose: To find a name in the hash
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.3.3
Date of Creation: 4/17/2019
Date of Last Revision: 4/18/2019
*/
void myHash::whereIs(string &word){

    //Name is not found by default
    found = false;

    //Find slot to search name for
    slot = ((int(word[0])) + (int(word[word.size() - 1]))) % 23;
    i = 0;

    //Search slot for name and if not in that slot move up one slot. Repeat
    while(found == false){
        if(i >= 23){
            cout<<"Name not found. "<<endl;
            found = true;
        }
        if(vHash[slot] == word){
            cout<<word<<" was found at position "<<slot<<endl;
            found = true;
        }
        else{
            slot++;
            i++;
        }
    }
}

/*
Purpose: To display the hash of names
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.1.1
Date of Creation: 4/16/2019
Date of Last Revision: 4/16/2019
*/
void myHash::display(){

    //Print out the hash
    for(i = 0; i <= (vHash.size() - 1); i++){
        cout<<endl<<"Position "<<i<<": "<<vHash[i];
    }
    cout<<endl;

}

