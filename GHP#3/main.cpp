/*
Purpose: To read a file and report how many words do not begin with d
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 3.13.4
Date of Creation: 2/18/2019
Date of Last Revision: 2/18/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    char file[50], //File name
         cText[1000], //Text in file
         word[50]; //Current word

    string text; //Text in file

    int i, //Location of character in text
        j, //Location of character in word
        k, //Location of character in file
        c = 0; //Number of words that start with a letter other than d

    //Get file name from user
    cout<<"Input filename to be searched: "<<endl;
    cin>>file;

    //assign pointer to file
    ifstream fptr(file);

    //Get text in file and copy to a character array
    while(getline(fptr, text)){
        strcat(cText, text.c_str());
        strcat(cText, " ");
    }

    //Print text in file
    cout<<cText<<endl<<endl;

    i = 0;

    //Take a whole word from file and put it into word
    for(k = 0; k < 10; k++){
        j = 0;
        while(cText[i] != ' '){
            word[j] = cText[i];
            i++;
            j++;
        }
        i++;

        //Check if starting letter is d
        if(word[0] != 'd' && word[0] != 'D'){
            c++;
        }
    }

    //Print total
    cout<<"Words that do not begin with the letter d: "<<c<<endl;

    return 0;
}
