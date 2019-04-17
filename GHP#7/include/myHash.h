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

        vector<string> vHash;
        string word;
        int slot,
            i;
        bool mpty,
             found;
};

#endif // MYHASH_H
