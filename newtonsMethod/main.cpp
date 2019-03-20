#include "newtonsMethod.h"

#include <iostream>

using namespace std;

int main()
{
    char f[50];
    int x,
        decimal,
        zero;

    cout<<"Input a function with respect to x (Ex. x^2+x-2): "<<endl;
    cin>>f;

    cout<<"Input the x value to start with: "<<endl;
    cin>>x;

    cout<<"Input the number of decimal places to calculate to: "<<endl;
    cin>>decimal;

    newtonsMethod(f, decimal, x);

}
