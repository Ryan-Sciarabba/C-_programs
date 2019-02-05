/*
Purpose: To create a magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 3.5.20
Date of Creation: 2/4/2019
Date of Last Revision: 2/4/2019
*/

/*
Purpose: To create a magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 4.6.5
Date of Creation: 2/4/2019
Date of Last Revision: 2/5/2019
*/

#include <iostream>
#include <iomanip>

using namespace std;

int three(void);
int five(void);
int seven(void);
int nine(void);
int eleven(void);
int matrix(int e[f][f],int f);

int main(){

    int d; //User-given matrix size

    //Ask the user for matrix size
    cout<<"Input a whole odd number from 3 to 11 for the size of the magic square: ";
    cin>>d;

    //Go to functions for each matrix size
    if(d == 3){
        three();
    }
    if(d == 5){
        five();
    }
    if(d == 7){
        seven();
    }
    if(d == 9){
        nine();
    }
    if(d == 11){
        eleven();
    }
    return 0;
}

int matrix(int e[],int f){

    int b, //number of spaces in the matrix
        c = 2, //Number to put into matrix
        i = 0, //Row
        j = (f / 2), //Column
        k = 0, //Row check
        l = (f / 2); //Column check

    //Populate the matrix with all 0's
    for(i = 0; i < f; i++){
        for(j = 0; j < f; j++){
                e[j] = 0;
        }
    }

    //Reset the row and column and populate a[0][1] with 1
    i = 0;
    j = f / 2;
    e[0][(f / 2)] = 1;

    //Populate the matrix with all numbers 1-9
    for(b = 1; b < (f * f); b++){
        k = i;
        l = j;
        if(i - 1 < 0){
            k = (f - 1);
            l++;
        }
        else{
            if(j + 1 > (f - 1)){
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
        e[i][j] = c;
        c++;
    }

    //Print the matrix
    cout<<"Matrix: "<<endl;

    for(i = 0; i < f; i++){
        for(j = 0; j < f; j++){
            cout<<setw(2)<<e[i][j]<<" "; //setw() changes the amount of space in front of the next printed value
        }
        cout<<endl;
    }
    return 0;
}
/*
Purpose: To create a 3x3 magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.1.5
Date of Creation: 2/5/2019
Date of Last Revision: 2/5/2019
*/

int three(void){

    int a[3][3]; //3x3 Matrix
    matrix(a[3][3], d);
}

/*
Purpose: To create a 5x5 magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.1.2
Date of Creation: 2/5/2019
Date of Last Revision: 2/5/2019
*/

int five(void){

    int a[5][5]; //5x5 Matrix
    int b, //number of spaces in the matrix
        c = 2, //Number to put into matrix
        i = 0, //Row
        j = 2, //Column
        k = 0, //Row check
        l = 2; //Column check

    //Populate the matrix with all 0's
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
                a[i][j] = 0;
        }
    }

    //Reset the row and column and populate a[0][3] with 1
    i = 0;
    j = 2;
    a[0][2] = 1;

    //Populate the matrix with all numbers 1-49
    for(b = 1; b < 25; b++){
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

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            cout<<setw(2)<<a[i][j]<<" "; //setw() changes the amount of space in front of the next printed value
        }
        cout<<endl;
    }
    return 0;
}

/*
Purpose: To create a 7x7 magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.1.2
Date of Creation: 2/5/2019
Date of Last Revision: 2/5/2019
*/

int seven(void){

    int a[7][7]; //7x7 Matrix
    int b, //number of spaces in the matrix
        c = 2, //Number to put into matrix
        i = 0, //Row
        j = 3, //Column
        k = 0, //Row check
        l = 3; //Column check

    //Populate the matrix with all 0's
    for(i = 0; i < 7; i++){
        for(j = 0; j < 7; j++){
            a[i][j] = 0;
        }
    }

    //Reset the row and column and populate a[0][3] with 1
    i = 0;
    j = 3;
    a[0][3] = 1;

    //Populate the matrix with all numbers 1-49
    for(b = 1; b < 49; b++){
        k = i;
        l = j;
        if(i - 1 < 0){
            k = 6;
            l++;
        }
        else{
            if(j + 1 > 6){
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

    for(i = 0; i < 7; i++){
        for(j = 0; j < 7; j++){
            cout<<setw(2)<<a[i][j]<<" "; //setw() changes the amount of space in front of the next printed value
        }
        cout<<endl;
    }
    return 0;
}

/*
Purpose: To create a 9x9 magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.1.2
Date of Creation: 2/5/2019
Date of Last Revision: 2/5/2019
*/


int nine(void){

    int a[9][9]; //9x9 Matrix
    int b, //number of spaces in the matrix
        c = 2, //Number to put into matrix
        i = 0, //Row
        j = 4, //Column
        k = 0, //Row check
        l = 4; //Column check

    //Populate the matrix with all 0's
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            a[i][j] = 0;
        }
    }

    //Reset the row and column and populate a[0][4] with 1
    i = 0;
    j = 4;
    a[0][4] = 1;

    //Populate the matrix with all numbers 1-81
    for(b = 1; b < 81; b++){
        k = i;
        l = j;
        if(i - 1 < 0){
            k = 8;
            l++;
        }
        else{
            if(j + 1 > 8){
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

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            cout<<setw(2)<<a[i][j]<<" "; //setw() changes the amount of space in front of the next printed value
        }
        cout<<endl;
    }
    return 0;
}

/*
Purpose: To create an 11x11 magic square
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.1.5
Date of Creation: 2/5/2019
Date of Last Revision: 2/5/2019
*/

int eleven(void){

    int a[11][11]; //11x11 Matrix
    int b, //number of spaces in the matrix
        c = 2, //Number to put into matrix
        i = 0, //Row
        j = 5, //Column
        k = 0, //Row check
        l = 5; //Column check

    //Populate the matrix with all 0's
    for(i = 0; i < 11; i++){
        for(j = 0; j < 11; j++){
            a[i][j] = 0;
        }
    }

    //Reset the row and column and populate a[0][5] with 1
    i = 0;
    j = 5;
    a[0][5] = 1;

    //Populate the matrix with all numbers 1-121
    for(b = 1; b < 121; b++){
        k = i;
        l = j;
        if(i - 1 < 0){
            k = 10;
            l++;
        }
        else{
            if(j + 1 > 10){
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

    for(i = 0; i < 11; i++){
        for(j = 0; j < 11; j++){
            cout<<setw(3)<<a[i][j]<<" "; //setw() changes the amount of space in front of the next printed value
        }
        for(j = 0; j < 11; j++){
        }
        cout<<endl;
    }
    return 0;
}
