#include <iostream>
#include "filing.h"

using namespace std;

int main()
{
    //One variable for each permutation
    int a,
        b,
        c,
        d;

    //Get a number
    cout<<"Input a number: ";
    cin>>a;

    //Go to each function
    d = addTwo(a);
    c = subTwo(a);
    b = mltTwo(a);
    a = dvdTwo(a);


    cout<<"Added Two: "<< d <<endl;
    cout<<"Subtracted Two: "<< c <<endl;
    cout<<"Multiply by Two: "<< b <<endl;
    cout<<"Divide by Two: "<< a <<endl;

    return 0;
}
