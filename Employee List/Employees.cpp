#include "Employees.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

Employees::Employees()
{
    eDatOut.open("tempData.txt");
    eDatOut.seekg(-1, ios::end);
    eDatOut.get(cLastID);
    lastID = int(cLastID);
    it = head;
    head = NULL;
}

void Employees::newEmployee(){

    eDatIn.open("empData.txt", ios::app);

    Employee *temp;

    temp = new Employee;
    cout<<"Employee's first name: ";
    cin>>temp->fName;
    cout<<"Employee's last name: ";
    cin>>temp->lName;
    cout<<"Employee's home address: ";
    cin.ignore();
    cin.getline(temp->sAddress, 100);
    cout<<"Employee's position: ";
    cin.getline(temp->position, 100);
    cout<<"Employee's age: ";
    cin>>temp->age;

    temp->id = lastID + 1;
    cout<<endl<<"Employee's ID# is: "<<temp->id<<endl<<endl;
    temp->next = NULL;

    eDatIn<<temp->fName<<" "<<temp->lName<<endl<<temp->sAddress<<endl<<temp->position<<endl<<temp->id<<endl<<endl;

    if(lastID == 0){
        head = temp;
    }
    if(lastID == 1){
        head->next = temp;
    }
    if(lastID != 0 && lastID != 1){
        it->next = temp;
    }

    it = temp;

    lastID++;

    eDatIn.close();
}

void Employees::idSearch(string empID){

    eDatOut.open("empData.txt", ios::out | ios::ate);

    if(getline(eDatOut, empID)){
        for(i = 0; i <= 4; i++){
            cout<<empID<<endl;
        }
    }
    eDatOut.close();
    /*
    if(head == NULL){
        cout<<">No employees to display<"<<endl<<endl;
    }
    else{
        found = false;
        it = head;

        while(found != true){
            if(stoi(empID) == it->id){
                cout<<endl<<">Employee found with ID#"<<it->id<<"<"<<endl;
                cout<<"Name: "<<it->fName<<" "<<it->lName<<endl;
                cout<<"Street Address: "<<it->sAddress<<endl;
                cout<<"Age: "<<it->age<<endl;
                cout<<"Position: "<<it->position<<endl<<endl;
                found = true;
            }
            if(it->next == NULL && found != true){
                cout<<">No employee found with matching ID number<"<<endl<<endl;
                found = true;
            }
            else{
                it = it->next;
            }
        }
    }
    */
}

void Employees::fNameSearch(string empFName){

    if(head == NULL){
        cout<<">No employees to display<"<<endl<<endl;
    }
    else{
        done = false;
        found = false;
        it = head;

        while(done != true){
            if(empFName.compare(it->fName) == 0){
                cout<<endl<<">Employee found with first name: "<<it->fName<<"<"<<endl;
                cout<<"Name: "<<it->fName<<" "<<it->lName<<endl;
                cout<<"Street Address: "<<it->sAddress<<endl;
                cout<<"Age: "<<it->age<<endl;
                cout<<"Position: "<<it->position<<endl;
                cout<<"ID#"<<it->id<<endl<<endl;
                found = true;
            }
            if(it->next == NULL){
                done = true;
            }
            it = it->next;
        }
        if(found == false){
            cout<<">No employee found with matching first name<"<<endl<<endl;
        }
    }
}

void Employees::lNameSearch(string empLName){

    if(head == NULL){
        cout<<">No employees to display<"<<endl<<endl;
    }
    else{
        done = false;
        found = false;
        it = head;

        while(done != true){
            if(empLName.compare(it->lName) == 0){
                cout<<endl<<">Employee found with last name: "<<it->lName<<"<"<<endl;
                cout<<"Name: "<<it->fName<<" "<<it->lName<<endl;
                cout<<"Street Address: "<<it->sAddress<<endl;
                cout<<"Age: "<<it->age<<endl;
                cout<<"Position: "<<it->position<<endl;
                cout<<"ID#"<<it->id<<endl<<endl;
                found = true;
            }
            if(it->next == NULL){
                done = true;
            }
            it = it->next;
        }
        if(found == false){
            cout<<">No employee found with matching last name<"<<endl<<endl;
        }
    }
}

void Employees::display(){

    if(head == NULL){
        cout<<">No employees to display<"<<endl<<endl;
    }
    else{
        it = head;
        done = false;

        while(done != true){
            cout<<endl<<">Employee ID#"<<it->id<<"  "<<"Name: "<<it->fName<<" "<<it->lName<<endl;
            if(it->next == NULL){
                done = true;
                cout<<endl;
            }
            it = it->next;
        }

    }
}

void Employees::dDisplay(){

    if(head == NULL){
        cout<<">No employees to display<"<<endl<<endl;
    }
    else{
        it = head;
        done = false;

        while(done != true){
            cout<<">Employee ID#"<<it->id<<"<"<<endl;
            cout<<"Name: "<<it->fName<<" "<<it->lName<<endl;
            cout<<"Street Address: "<<it->sAddress<<endl;
            cout<<"Age: "<<it->age<<endl;
            cout<<"Position: "<<it->position<<endl<<endl;
            if(it->next == NULL){
                done = true;
            }
            it = it->next;
        }
    }
}




