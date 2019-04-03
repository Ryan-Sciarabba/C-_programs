/*
Purpose: To take a word and determine using a stack and queue if it is a palindrome
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.1.5
Date of Creation: 4/3/2019
Date of Last Revision: 4/3/2019
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    string word; //String of word input by user

    int i; //Integer to push characters onto a stack and queue

    bool a = true; //Boolean for palindrome checker

    stack<char> sPal; //Stack version of word
    queue<char> qPal; //Queue version of word

    //Take user input and store in 'word'
    cout<<"Input a word to see if it is a palindrome: ";
    cin>>word;
    cout<<endl<<endl;

    //Push characters onto stack and queue
    for(i = 0; i <= (word.length() - 1); i++){
        sPal.push(word[i]);
        qPal.push(word[i]);
    }

    //Check to see if stack is empty and compare letters
    while(!sPal.empty() && a == true){
        if(sPal.top() == qPal.front()){
            sPal.pop();
            qPal.pop();
            a = true;
        }
        else{
            a = false;
        }
    }

    //If a is true the word is a palindrome
    if(a == true){
        cout<<word<<" is a palindrome"<<endl;
    }
    else{
        cout<<word<<" is not a palindrome"<<endl;
    }

    return 0;
}
