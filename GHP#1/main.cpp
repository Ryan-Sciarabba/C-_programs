/*
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.10.8
Date of Creation: 1/28/2019
Date of Last Revision: 1/28/2019
*/
#include <iostream>

using namespace std;

int main()
{
    int a[2][2];
    int b,
        i,
        j,
        k,
        l;
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    cout<<"Matrix:"<<endl;
    cout<<a[0][0]<<" "<<a[0][1]<<endl;
    cout<<a[1][0]<<" "<<a[1][1]<<endl<<endl;
    cout<<"Input a whole number between 1 and 4 to search the matrix for: ";
    cin>>b;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            if(a[i][j] == b){
                k = i;
                l = j;
            }
            else{
            }
        }
    }
    cout<< b <<" is in row "<< k + 1 <<" and column "<< l + 1 <<endl;
}
