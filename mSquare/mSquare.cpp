#include "mSquare.h"

#include <iostream>
#include <iomanip>

using namespace std;

void mSquare(int matrix[][127], int size){

    int cMax = size, //Max column
        c = 0, //Column
        r = 0, //Row
        k = 0, //Column check
        l = 0, //Row check
        f; //Fill number

    //Populate the matrix with all 0's
    for(c = 0; c < size; c++){
        for(r = 0; r < size; r++){
                matrix[r][c] = 0;
        }
    }

    //Reset the row and column and populate the top, middle most space with 1
    r = 0;
    c = cMax / 2;
    matrix[0][(cMax / 2)] = 1;

    //Populate the matrix with all numbers
    for(f = 2; f <= (size * size); f++){

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
}
