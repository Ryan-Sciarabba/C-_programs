#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;

//Written by: Ryan Sciarabba
//Date of last revision: 10/2/2019
//Language: C++ (GCC compiler)
int main(int argc, char*argv[]){

    //Check for output file
    if(argc != 2){
        cout << "ERROR: Invalid number of arguments. Requires 2 but only got " << argc;
        _Exit(0);
    }

    ofstream file(argv[1]); //Output file
    int bitNum; //length of bit pattern
    string binary; //Binary number
    binary.resize(1000000);

    //Get length of bit pattern
    cout<<"Input number of bits to be output: ";
    cin>>bitNum;

    //Set default pattern to all 0's
    cout<<"CREATING DEFAULT...\n";
    for(int i = 0; i < bitNum; i++){
        binary[i] = '0';
    }

    //Number of computations to figure out
    cout<<"CALCULATING MAX CALCULATIONS...\n";
    int maxBit = pow(2, bitNum);

    //Output to file
    cout<<"OUTPUTTING TO FILE...\n";
    for(int i = 0; i < maxBit; i++){
        cout<<i<<" / "<<maxBit<<" bit patterns written... \n";
        for(int k = 0; k < bitNum; k++){
                file<<binary[k];
        }
        file<<"\n";

        //Flip digits
        int j = 0;
        int l = bitNum - 1;
        while(j < bitNum){
            if(binary[l] == '0'){
                binary[l] = '1';
                break;
            }
            else{
                binary[l] = '0';
                j++;
                l--;
            }
        }
    }
    cout<<"DONE!";
    return 0;
}
