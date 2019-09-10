#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

int main(int argc, char*argv[]){

    if(argc != 2){
        cout << "ERROR: Invalid number of arguments. Requires 2 but only got " << argc;
    }
    else{
        ifstream file(argv[1]);
        string line;
        char ns1[1000], ns2[1000], ns3[1000], temp;
        int n1, n3, i, j;

        while(getline(file, line)){
            cout << line << "\n\n";
            line.append(" ");
            if(line[0] != '#'){
                istringstream iss(line);
                iss >> ns1 >> ns2 >> ns3;

                n1 = stoi(ns1);
                n3 = stoi(ns3);

            }
            else{
                continue;
            }
        }
    }
    return 0;
}
