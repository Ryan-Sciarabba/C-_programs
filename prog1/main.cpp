#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char*argv[]){

    if(argc != 2){
        cout << "ERROR: Invalid number of arguments. Requires 2 but only got " << argc;
    }
    else{
        ifstream file(argv[1]);
        string line, base;
        string temp;
        char cTemp;
        string ns1, ns2, ns3;
        int n1, n3, i, exp, dec;

        while(getline(file, line)){
            line.append(" ");
            if(line[0] != '#'){
                istringstream iss(line);
                iss >> ns1 >> ns2 >> ns3;

                n1 = stoi(ns1);
                n3 = stoi(ns3);

                exp = ns2.size() - 1;
                dec = 0;
                i = 0;

                while(exp >= 0){
                    if(ns2[i] >= 'A' && ns2[i] <= 'Z'){
                        ns2[i] = ns2[i] - 'A' + 'a';
                    }
                    if(ns2[i] >= 'a' && ns2[i] <= 'z'){
                        ns2[i] = (int)(ns2[i] - 'a' + 10);
                    }
                    if(ns2[i] >= '0' && ns2[i] <= '9'){
                        ns2[i] = (int)ns2[i] - 48;
                    }
                    cout<<"Dec and exp: "<<dec<<" "<<exp<<"\n";
                    cout<<ns2[i];
                    dec = dec + (ns2[i] * (pow(n1, exp)));
                    exp--;
                    i++;
                }
                while(dec > 0){
                    if(dec < n3){
                        temp = dec;
                        base.append(temp);
                        dec = 0;
                    }
                    else{
                        cTemp = dec % n3; //GOTTA FIGURE OUT HOW TO MAKE THE INTEGER CALCULATION WORK
                        if(cTemp >= 'A' && ns2[i] <= 'Z'){
                            ns2[i] = ns2[i] - 'A' + 'a';
                        }
                        if(ns2[i] >= 'a' && ns2[i] <= 'z'){
                            ns2[i] = (int)(ns2[i] - 'a' + 10);
                        }
                        base.append(temp);
                        dec = dec / n3;
                    }
                }
                cout<<"Converted: "<<base<<"\n";
            }
            else{
                continue;
            }
        }
    }
    return 0;
}
