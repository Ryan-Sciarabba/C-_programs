#include "noD.h"

#include <iostream>

using namespace std;

int main()
{
    char name[50];

    cout<<"File name: "<<endl;
    cin>>name;

    if(noD(name) != -1){
        cout<<"Words without D: "<<noD(name)<<endl;
    }

    else{
        cout<<endl<<"ERROR file not found"<<endl;
    }

    return 0;
}
