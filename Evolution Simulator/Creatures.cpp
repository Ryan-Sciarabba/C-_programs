#include "Creatures.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

Creatures::Creatures(int numCreatures){

    srand(time(NULL));
    lastCreature = false;

    for(i = 1; i <= numCreatures; i++){
        temp = new Creature;
        temp->cNum = i;
        temp->modMin = rand() % 2 + 0;
        temp->modMax = rand() % 3 + 2;
        temp->fitness = 1;
        temp->next = NULL;

        if(i == 1){
            head = temp;
        }
        if(i == 2){
            head->next = temp;
        }
        if(i != 1 && i != 2){
            it->next = temp;
        }
        it = temp;

        cout<<"Creature "<<temp->cNum<<":   Fitness: "<<temp->fitness<<"    Adaptation Range: "<<temp->modMin<<"-"<<temp->modMax<<endl;
    }
    cout<<endl;
}

void Creatures::Evolve(){

    ClearScreen();
    Display();

    cout<<">Entering Evolution and Mutation<"<<endl<<endl;

    it = head;
    lastCreature = false;

    while(lastCreature != true){
        mod = (rand() % it->modMax + it->modMin);
        it->fitness = mod + it->fitness;

        if(it->next == NULL){
            lastCreature = true;
        }
        cout<<"Creature "<<it->cNum<<":   Fitness: "<<it->fitness<<"    Adaptation Range: "<<it->modMin<<"-"<<it->modMax<<"    Actual Adaptation: "<<mod<<endl;
        it = it->next;
    }

    Create();
    Kill();
}

void Creatures::Create(){

    it = head;
    temp = it->next;
    lastCreature = false;

    cout<<endl<<">Entering creature creation<"<<endl;
    while(lastCreature != true){
        if(temp->next == NULL){
            tail = temp;
            lastCreature = true;
        }
        if(it->fitness < temp->fitness){
            it = temp;
            temp = it->next;
        }
        else{
            temp = temp->next;
        }
    }
    cout<<">Largest creature clones itself and it's clone has a chance of becoming better or worse<"<<endl;
    cout<<"Creature "<<it->cNum<<":    Fitness: "<<it->fitness<<"    Adaptation Range: "<<it->modMin<<"-"<<it->modMax<<endl<<endl;
    temp = new Creature;
    temp->cNum = it->cNum + 0.1;
    temp->modMin = it->modMin + ((rand() % 2 + 0) - 1);
    temp->modMax = it->modMax + ((rand() % 2 + 0) - 1);
    temp->fitness = it->fitness;
    temp->next = NULL;

    tail->next = temp;
    tail = tail->next;

    i++;

    Display();
}

void Creatures::Kill(){

    small = head;
    temp = small->next;
    lastCreature = false;

    cout<<endl<<">Entering creature extinction<"<<endl;
    while(lastCreature != true){
        if(temp->next == NULL){
            tail = temp;
            lastCreature = true;
        }
        if(small->fitness > temp->fitness){
            small = temp;
            temp = small->next;
        }
        else{
            temp = temp->next;
        }
    }
    cout<<">Smallest creature dies<"<<endl;
    cout<<"Creature "<<small->cNum<<":    Fitness: "<<small->fitness<<"    Adaptation Range: "<<small->modMin<<"-"<<small->modMax<<endl<<endl;
    if(small == head){ClearScreen();
        head = small->next;
        small = NULL;
    }
    else{
        if(small->next == NULL){
            temp = head;
            while(temp->next != small){
                temp = temp->next;
            }
            temp->next = NULL;
        }
        if(small->next != NULL){
            temp = small->next;
            it = head;
            while(it->next != small){
                it = it->next;
            }
            it->next = temp;
        }
    }
    Display();
}

void Creatures::Display(){

    temp = head;
    lastCreature = false;

    while(lastCreature != true){
        cout<<"Creature "<<temp->cNum<<":   Fitness: "<<temp->fitness<<"    Adaptation Range: "<<temp->modMin<<"-"<<temp->modMax<<endl;
        temp = temp->next;
        if(temp->next == NULL){
            cout<<"Creature "<<temp->cNum<<":   Fitness: "<<temp->fitness<<"    Adaptation Range: "<<temp->modMin<<"-"<<temp->modMax<<endl<<endl;
            lastCreature = true;
        }
    }
}

void Creatures::ClearScreen(){
    cout<<string(100, '\n');
}
