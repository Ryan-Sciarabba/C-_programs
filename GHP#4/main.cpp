/*
Purpose: To take in a number and display its prime factors
Written by: Ryan Sciarabba using Nyhoff's stack class
Language: C++ (g++ target)
Version: 1.3.7
Date of Creation: 3/6/2019
Date of Last Revision: 3/6/2019
*/

#include <iostream>

using namespace std;

#include "stack.h"

int main()
{
    Stack iStack; //Create a stack

    int num, //Number given by user
        fac, //Prime factor
        i = 2; //Number to divide num by

    //Get number from user
    cout<<"Input a positive whole number: ";
    cin>>num;

    //Check if number can be divided evenly and if so add factor to the stack
    while(num > 1){
        if(num % i == 0){
            fac = i;
            iStack.push(fac);
            num = num / i;
        }
        else{
            i++;
        }
    }

    //Print out prime factors
    cout<<endl<<"Prime Factors"<<endl<<"----------"<<endl;
    iStack.display(cout);

    return 0;
}
