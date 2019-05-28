#ifndef CREATURES_H
#define CREATURES_H

using namespace std;

class Creature{

    public:

        double cNum;

        int modMin,
            modMax,
            fitness;

        Creature *next;
};

class Creatures{

    public:
        Creatures(int numCreatures);

        void Evolve();
        void Create();
        void Kill();
        void Display();
        void ClearScreen();
    private:

        int i,
            mod;

        bool lastCreature;

        Creature *head, *it, *temp, *small, *tail;
};
#endif // CREATURES_H
