#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int a;
    double b;
    char c;
    char d[20];
    int len_of_string;
    cout<<"Enter an integer: ";
    cin>>a;
    cout<<"Enter a real number: ";
    cin>>b;
    cout<<"Enter a character: ";
    cin>>c;
    cout<<"Enter a string: ";
    cin>>d;
    len_of_string = strlen(d);
    cout<<"The integer is "<< a <<" the real is "<< b << endl;
    cout<<"The character is "<< c <<" the string is "<< d << endl;
    cout<<"The length of the string is "<< len_of_string << endl;
    return 0;
}
