//Written by: Ryan Sciarabba
//Date of last revision: 9/10/2019
//Language: C++ (GCC compiler)

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char*argv[]){

    //Check for input file
    if(argc != 2){
        cout << "ERROR: Invalid number of arguments. Requires 2 but only got " << argc;
    }
    else{

        ifstream file(argv[1]); //File to use
        string line, base; //Line read // final converted number
        string temp; //Temporary storage of numbers
        char rem; //Remainder of division
        string ns1, ns2, ns3; //Starting base //Number to convert //Final base
        int n1, n3, i, j, exp, dec, comp, m; //Starting base //Final base //Iterator //Iterator //Exponent //Decimal //Number of computations //Number for pow calculation

        comp = 1;
        //Read lines from file
        while(getline(file, line)){
            line.append(" ");

            //Weed out comments
            if(line[0] != '#'){

                //Turn single line into multiple strings
                istringstream iss(line);
                iss >> ns1 >> ns2 >> ns3;

                //Change to integers
                n1 = stoi(ns1);
                n3 = stoi(ns3);

                //Set variables
                exp = ns2.size() - 1; //Exponent is set to one less than the size of the number
                dec = 0; //Total decimal is set to zero to start
                i = 0; //Iterator to move through strings

                //This is where the fun begins. (Not really)
                while(exp >= 0){

                    //Change letters to numbers to be added to the decimal
                    if(ns2[i] >= 'A' && ns2[i] <= 'Z'){
                        ns2[i] = ns2[i] - 'A' + 'a';
                    }
                    if(ns2[i] >= 'a' && ns2[i] <= 'z'){
                        ns2[i] = (ns2[i] - 'a' + 10);
                    }
                    if(ns2[i] >= '0' && ns2[i] <= '9'){
                        ns2[i] = ns2[i] - 48;
                    }

                    //Add to decimal
                    j = 1;
                    m = n1;
                    while(j < exp){
                        m = m * n1;
                        j++;
                    }
                    if(exp == 0){
                        m = 1;
                    }
                    dec = dec + (ns2[i] * m);
                    exp--;
                    i++;

                }


                base.clear();
                //Now we start the devision
                while(dec >= 0){
                    //Make sure the decimal is still larger than the remainder and if not just add the remainder to the total
                    if(dec < n3){

                        rem = dec + 55;

                        //If the remainder is in the letter range, make it lower-case. Otherwise subtract 7 to make it the correct ASCII number
                        if(rem >= 'A' && rem <= 'Z'){
                            rem = rem - 'A' + 'a';
                        }
                        else{
                            rem = rem - 7;
                        }
                        temp = rem;
                        base.insert(0, temp);
                        dec = -1;
                    }

                    //Otherwise divide and find remainders
                    else{
                        rem = dec % n3 + 55;
                        //If the remainder is in the letter range, make it lower-case. Otherwise subtract 7 to make it the correct ASCII number
                        if(rem >= 'A' && rem <= 'Z'){
                            rem = rem - 'A' + 'a';
                        }
                        else{
                            rem = rem - 7;
                        }

                        //Add the remainder to the string
                        temp = rem;
                        base.insert(0, temp);
                        dec = dec / n3;
                    }
                }
                //Print result and add one to computation counter
                cout<<comp<<"   "<<base<<"\n";
                comp++;
            }
            //Bypass any lines that will not be computed
            else{
                continue;
            }
        }
    }
    return 0;
}
