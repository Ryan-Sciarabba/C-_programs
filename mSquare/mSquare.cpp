#include "mSquare.h"

#include <iostream>
#include <iomanip>

using namespace std;

int mSquare(int matrix[127][127], int mSize){

    if((mSize % 2) == 0 && mSize > 1 && mSize < 127){
        cout<<"ERROR: Number is even. ";
        return 1;
    }
    if(mSize < 1){
        cout<<"ERROR: Number is less than 1. ";
        return 1;
    }
    if(mSize > 127){
        cout<<"ERROR: Number is greater than 127. ";
        return 1;
    }

    int cMax = mSize, //Max column
        c = 0, //Column
        r = 0, //Row
        k = 0, //Column check
        l = 0, //Row check
        f; //Fill number

    //Populate the matrix with all 0's
    for(c = 0; c < mSize; c++){
        for(r = 0; r < mSize; r++){
                matrix[r][c] = 0;
        }
    }

    //Reset the row and column and populate the top, middle most space with 1
    r = 0;
    c = cMax / 2;
    matrix[0][(cMax / 2)] = 1;

    //Populate the matrix with all numbers
    for(f = 2; f <= (mSize * mSize); f++){

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
        if(matrix[l][k] == 0){
            c = k;
            r = l;
        }
        else{
            r++;
        }
        matrix[r][c] = f;
    }
    return 0;
}
