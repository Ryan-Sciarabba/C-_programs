#include <iostream>
#include "Creatures.h"

using namespace std;

int main()
{
    int numCreatures;
    char quit[1];

    cout<<"How many creatures would you like to simulate? ";
    cin>>numCreatures;

    Creatures aliens(numCreatures);

    while(quit[0] != 'y'){
        aliens.Evolve();
        cout<<"Quit? ";
        cin>>quit;
    }
    return 0;
}
