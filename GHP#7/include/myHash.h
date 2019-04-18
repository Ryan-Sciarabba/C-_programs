#ifndef MYHASH_H
#define MYHASH_H

#include <vector>
#include <string>

using namespace std;

class myHash
{
    public:
        myHash();

        void store(string &word);

        void whereIs(string &word);

        void display();

    private:

        vector<string> vHash; //Hash for names
        string word; //Name
        int slot, //Slot in the hash to put name into
            i; //Display iterator
        bool mpty, //Is the slot empty boolean
             found; //Is name found boolean
};

#endif // MYHASH_H
