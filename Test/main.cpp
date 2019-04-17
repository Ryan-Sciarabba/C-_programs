#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    int slot, c;
    a = 'ryas';
    c = a.size() - 1;
    slot = int(a[c]);
    cout<<slot<<endl;
    return 0;
}
