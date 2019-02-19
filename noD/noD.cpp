#include "noD.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int noD(char *fileN){

      char cText[1000], //Text in file
           word[50]; //Current word

    string text; //Text in file

    int i, //Location of character in text
        j, //Location of character in word
        k, //Location of character in file
        c = 0; //Number of words that start with a letter other than d

    bool d = true; //Loop controller

    //assign pointer to file
    ifstream fptr(fileN); //USED TO BE file

    //Check if file exists
    if(fptr){

        //Get text in file and copy to a character array
        while(getline(fptr, text)){
            strcat(cText, text.c_str());
            strcat(cText, " ");
        }

        //Make sure the ending characters on the character array are spaces
        strcat(cText, "        ");

        //Print text in file
        cout<<cText<<endl<<endl;

        i = 0;
        //Take a whole word from file and put it into word
        while(d == true){
            j = 0;
            while(cText[i] != ' '){
                word[j] = cText[i];
                i++;
                j++;
            }
            i++;

            //Check if starting letter is d and if not add 1 to c
            if(word[0] != 'd' && word[0] != 'D'){
                c++;
            }

            //Reset the word array for cleanness
            for(j = 0; j <= 50; j++){
                word[j] = ' ';
            }

            //Check to see if ending characters are spaces to end loop
            if(cText[i] == ' ' && cText[i + 1] == ' '){
                d = false;
                //cout<<"Help I can't get out of the loop and I don't know why"<<endl;
            }
        }
        return c;
    }

    //File not found error
    else{
        return -1;
    }
}
