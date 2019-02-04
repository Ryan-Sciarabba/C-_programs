/*
Purpose: To create a magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 3.5.20
Date of Creation: 2/4/2019
Date of Last Revision: 2/4/2019
*/

#include <iostream>

using namespace std;

int main2()
{
    int a[3][3]; //5x5 Matrix
    int b, //number of spaces in the matrix
        c = 2, //Number to put into matrix
        i = 0, //Row
        j = 1, //Column
        k = 0, //Row check
        l = 1; //Column check

    //Populate the matrix with all 0's
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
                a[i][j] = 0;
        }
    }

    //Reset the row and column and populate a[0][2] with 1
    i = 0;
    j = 1;
    a[0][2] = 1;

    //Populate the matrix with all numbers 1-25
    for(b = 1; b < 9; b++){
        k = i;
        l = j;
        if(i - 1 < 0){
            k = 4;
            l++;
        }
        else{
            if(j + 1 > 4){
                l = 0;
                k--;
            }
            else{
                k--;
                l++;
            }
        }
        if(a[k][l] == 0){
            i = k;
            j = l;
        }
        else{
            i++;
        }
        a[i][j] = c;
        c++;
    }

    //Print the matrix
    cout<<"Matrix: "<<endl;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
