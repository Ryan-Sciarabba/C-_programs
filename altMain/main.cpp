/*
ver: 1.6.3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ifstream fPointer("dictionary.txt"); //Name of file to be searched

    string word; //Word to be processed

    int i, //Integer for loops
        palNum = 0, //Number of palindromes
        wrdNum = 0; //Number of words processed

    bool a = true; //Boolean for palindrome checker

    stack<char> sPal; //Stack version of word
    queue<char> qPal; //Queue version of word

    //Print start of palindrome list
    cout<<"Palindromes: ";

    //Check file for first line
    while(getline(fPointer, word)){

        //Push characters onto stack and queue from file line
        for(i = 0; i <= (word.length() - 1); i++){
            sPal.push(word[i]);
            qPal.push(word[i]);
        }

        //Check to see if word is a palindrome
        while(!sPal.empty() && a == true){

            if(sPal.top() == qPal.front()){
                a = true;
            }
            else{
                a = false;
            }
            sPal.pop();
            qPal.pop();
        }

        //If word is a palindrome add one to palNum and print word
        if(a == true){
            palNum++;
            cout<<word<<"  ";
        }

        //Add one to words processed and reset stack, queue and boolean
        wrdNum++;

        while(!qPal.empty()){
            qPal.pop();
        }
        while(!sPal.empty()){
            sPal.pop();
        }
        a = true;
    }

    //Print totals
    cout<<endl<<endl<<"Words that are palindromes: "<<palNum<<endl;
    cout<<"Words processed: "<<wrdNum<<endl;

    return 0;
}

