#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

int unsign(string binary);
string sign(string binary);
string onesComp(string binary);
string twosComp(string binary);
string positive(string binary);
string negative(string binary);

int main(int argc, char*argv[]){

    if(argc != 2){
        cout << "ERROR: Invalid number of arguments. Requires 2 but only got " << argc;
        _Exit(0);
    }

    ifstream file(argv[1]);
    string input;

    while(getline(file, input)){
        cout<<unsign(input)<<" "<<sign(input)<<" "<<onesComp(input)<<" "<<twosComp(input);
    }
    return 0;
}

int unsign(string binary){
    int decimal = 0;
    for(int i = 10; i > 0; i--){
        if(binary[i] == '1'){
            if(i == 1){
                decimal += 1;
            }
            else{
                decimal += pow(2, 9 - i);
            }
        }
    }
    return decimal;
}

string sign(string binary){
    if(binary[0] == '1'){
        return negative(binary);
    }
    else{
        return positive(binary);
    }
}

string onesComp(string binary){
    if(binary[0] == '1'){
        for(int i = 0; i < 10; i++){
            if(binary[i] == '1'){
                binary[i] = '0';
            }
            else{
                binary[i] = '1';
            }
        }
        return negative(binary);
    }
    else{
        return positive(binary);
    }
}

string twosComp(string binary){
    onesComp(binary);
    binary[(int)binary.length() - 1] + 1;
    return binary;
}

string positive(string binary){
    string num = to_string(unsign(binary));
    num.insert(0, "+");
    return num;
}

string negative(string binary){
    binary[0] = '0';
    string num = to_string(unsign(binary));
    num.insert(0, "-");
    return num;
}
