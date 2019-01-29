#include <iostream>

using namespace std;

int main(void){
        int a[1][1];
        int i,
            j;

        for(i = 1; i < 3; i++){
            for(j = 1; j < 3; j++){
                cout<<"Enter integer to be put into matrix position "<< i << ", "<< j <<": ";
                cin>>a[i][j];
            }
        }
        cout<<"Matrix"<<endl;
        cout<< a[1][1] <<" "<< a[1][2]<<endl;
        cout<< a[2][1] <<" "<< a[2][2]<<endl;
        return 0;
 }
