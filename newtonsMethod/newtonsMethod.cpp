#include "newtonsMethod.h"

#include <iostream>
#include <string>

using namespace std;

int newtonsMethod(char *fox, int dPlaces, int a){

    char term;

    string fpox;

    int i,
        j,
        power,
        length;

    fpox = fox;

    for(i = 0; term != 'x'; i++){
        term = fpox[i];

        if(fpox[i + 1] == '^'){
            power = fpox[i + 2]; //Set power to what x is powered to
            for(j = fpox.len(); j >= fpox[i - 1]; j--){
                fpox[j] = fpox[j + 1];
            }
            fpox[i - 1] = power
            fpox[i + 2] = power - 1;
        }
    cout<<fpox<<endl;

    return power;

}
