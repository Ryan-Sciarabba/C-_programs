#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
  {
  string line;
  ifstream myfile( "example.txt" );
  if (myfile)  // same as: if (myfile.good())
    {
    while (getline( myfile, line ))  // same as: while (getline( myfile, line ).good())
      {
      if (line == "d")
        {
        cout<<"Cool";
        }
      }
    myfile.close();
    }
  else cout << "fooey\n";

  return 0;
  }
