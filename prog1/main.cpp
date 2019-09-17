//Written by: Ryan Sciarabba
//Date of last revision: 9/12/2019
//Language: C++ (GCC compiler)

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>

using namespace std;

int baseToDec(int base, string str);
string decToBase(int decimal, int base);

int main(int argc, char*argv[]){

    //Check for input file
    if(argc != 2){
        cout << "ERROR: Invalid number of arguments. Requires 2 but only got " << argc;
        _Exit(0);
    }

    ifstream file(argv[1]); //File to use
    string line;//Line read
    string ns2; //Number to convert
    string converted; //Converted number to correct base
    int n1, n3, comp, d1;//Starting base //Final base //Number of computations //Decimal

    comp = 1;

    //Read lines from file
    while(getline(file, line)){
        line.append(" ");

        //Weed out comments
        if(line[0] == '#' || line[0] == ' ')continue;

        //Take input from line
        istringstream iss(line);
        iss >> n1 >> ns2 >> n3;

        //Compute decimal
        d1 = baseToDec(n1, ns2);

        //Compute converted number
        converted.append(decToBase(d1, n3));

        //Print result, add one to computation counter, clear old computed result
        cout<<comp<<"   "<<converted<<"\n";
        comp++;
        converted.clear();
    }
}

//Function to convert number from a base to a decimal
//Written by: Ryan Sciarabba
//Date of last revision: 9/12/2019
//Language: C++ (GCC compiler)
int baseToDec(int base, string str){

    //Set variables
    int exp = str.size() - 1; //Exponent is set to one less than the size of the number
    int dec = 0; //Total decimal is set to zero to start
    int i = 0; //Iterator to move through strings

    //This is where the fun begins. (Not really)
    while(exp >= 0){

        //Change letters to numbers to be added to the decimal
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = (str[i] - 'a' + 10);
        }
        if(str[i] >= '0' && str[i] <= '9'){
            str[i] = str[i] - 48;
        }

        //Compute power
        int j = 1;
        int m = base;
        while(j < exp){
            m = m * base;
            j++;
        }
        if(exp == 0){
            m = 1;
        }

        //Add to decimal
        dec = dec + (str[i] * m);
        exp--;
        i++;
    }
    return dec;
}

//Function to convert number from decimal to base
//Written by: Ryan Sciarabba
//Date of last revision: 9/12/2019
//Language: C++ (GCC compiler)
string decToBase(int decimal, int base){

    string sBase, temp; //String to add computation to //Temporary string for computation
    char rem; //Remainder of devision

    //Make sure previous base string is clear
    sBase.clear();

    //Now we start the devision
    while(decimal >= 0){

        //Make sure the decimal is still larger than the remainder and if not just add the remainder to the total
        if(decimal < base){
            rem = decimal + 55;
            decimal = -1;
        }

        //Divide and add remainders
        else{
            rem = decimal % base + 55;
            decimal = decimal / base;
        }

        //If the remainder is in the letter range, make it lower-case.
        if(rem >= 'A' && rem <= 'Z'){
            rem = rem - 'A' + 'a';
        }

        //Otherwise subtract 7 to make it the correct ASCII number
        else{
            rem = rem - 7;
        }

        //Add the remainder to the string
        temp = rem;
        sBase.insert(0, temp);
    }
    return sBase;
}
