#include "mSquare.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a[127][127], //Matrix max size
        b, //Size of the matrix
        c,
        r;

    //Ask the user for matrix size
    cout<<"Input a whole odd number from 1 to 127 to compute a magic square: ";
    cin>>b;

    mSquare(a, b);

    cout<<"Matrix:"<<endl;

    for(c = 0; c < b; c++){
        for(r = 0; r < b; r++){
            cout<<setw(4)<<a[c][r]<<" "; //setw() changes the amount of space in front of the next printed value
        }
        cout<<endl;
    }

    return 0;
}
