/*
Purpose: To create a magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 5.5.8
Date of Creation: 2/4/2019
Date of Last Revision: 2/13/2019
*/

#include <iostream>
#include <iomanip>

using namespace std;



int main(){

    int a[127][127], //Matrix max size
        b; //Size of the matrix

    //Ask the user for matrix size
    cout<<"Input a whole odd number from 1 to 127 to compute a magic square: ";
    cin>>b;

    int cMax = b, //Max column
        c = 0, //Column
        r = 0, //Row
        k = 0, //Column check
        l = 0, //Row check
        f; //Fill number

    //Populate the matrix with all 0's
    for(c = 0; c < b; c++){
        for(r = 0; r < b; r++){
                a[r][c] = 0;
        }
    }

    //Reset the row and column and populate the top, middle most space with 1
    r = 0;
    c = cMax / 2;
    a[0][(cMax / 2)] = 1;

    //Populate the matrix with all numbers
    for(f = 2; f <= (b * b); f++){

        k = c;
        l = r;
        if(l - 1 < 0){
            l = (cMax - 1);
            if(k + 1 > cMax - 1){
                k = 0;
            }
            else{
                k++;
            }
        }
        else{
            if(k + 1 > cMax - 1){
                k = 0;
                l--;
            }
            else{
                l--;
                k++;
            }
        }
        if(a[l][k] == 0){
            c = k;
            r = l;
        }
        else{
            r++;
        }
        a[r][c] = f;
    }

    //Print the matrix
    cout<<"Matrix: "<<endl;

    for(c = 0; c < b; c++){
        for(r = 0; r < b; r++){
            cout<<setw(4)<<a[c][r]<<" "; //setw() changes the amount of space in front of the next printed value
        }
        cout<<endl;
    }
    return 0;
}
