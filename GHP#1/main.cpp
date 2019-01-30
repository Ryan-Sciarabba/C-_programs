/*
Purpose: To search a matrix for a user-given value
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.10.11
Date of Creation: 1/28/2019
Date of Last Revision: 1/30/2019
*/
#include <iostream>

using namespace std;

int main()
{
    int a[2][2]; //2x2 matrix
    int b, //User input value
        i, //Row increment
        j, //Column increment
        k, //Row comparator
        l; //Column comparator

    //Populate the matrix
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    //Print out the matrix to the user
    cout<<"Matrix:"<<endl;
    cout<<a[0][0]<<" "<<a[0][1]<<endl;
    cout<<a[1][0]<<" "<<a[1][1]<<endl<<endl;

    //Search for a number
    cout<<"Input a whole number between 1 and 4 to search the matrix for: ";
    cin>>b;
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2 ; j++){
            if(a[i][j] == b){ //If the input number and the current number are equal store the value of its column and row
                k = i;
                l = j;
            }
        }
    }
    //Print where the number is in the matrix
    cout<< b <<" is in row "<< k + 1 <<" and column "<< l + 1 <<endl;

    return 0;
}
