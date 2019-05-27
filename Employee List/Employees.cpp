#include "Employees.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Employees::Employees()
{
    lastID = 0;
    it = head;
    head = NULL;
}

void Employees::newEmployee(){

    Employee *temp;

    temp = new Employee;
    cout<<"Employee's first name: ";
    cin>>temp->fName;
    cout<<"Employee's last name: ";
    cin>>temp->lName;
    cout<<"Employee's home address: ";
    cin>>temp->sAddress;
    cin.getline(temp->sAddress, 100);
    cout<<"Employee's position: ";
    cin>>temp->position;
    cout<<"Employee's age: ";
    cin>>temp->age;

    temp->id = lastID + 1;
    cout<<endl<<"Employee's ID# is: "<<temp->id<<endl<<endl;
    temp->next = NULL;

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
}

void Employees::idSearch(string empID){

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
}

void Employees::fNameSearch(string empFName){

    if(head == NULL){
        cout<<">No employees to display<"<<endl<<endl;
    }
    else{
        found = false;
        it = head;

        do{
            if(empFName == it->fName){
                cout<<endl<<">Employee found with first name: "<<it->fName<<"<"<<endl;
                cout<<"Name: "<<it->fName<<" "<<it->lName<<endl;
                cout<<"Street Address: "<<it->sAddress<<endl;
                cout<<"Age: "<<it->age<<endl;
                cout<<"Position: "<<it->position<<endl;
                cout<<"ID#"<<it->id<<endl<<endl;
                found = true;
            }
            it = it->next;
        } while(it->next != NULL);
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
        found = false;
        it = head;

        do{
            if(empLName == it->lName){
                cout<<endl<<">Employee found with last name: "<<it->lName<<"<"<<endl;
                cout<<"Name: "<<it->fName<<" "<<it->lName<<endl;
                cout<<"Street Address: "<<it->sAddress<<endl;
                cout<<"Age: "<<it->age<<endl;
                cout<<"Position: "<<it->position<<endl;
                cout<<"ID#"<<it->id<<endl<<endl;
                found = true;
            }
            it = it->next;
        } while(it->next != NULL);
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

        do{
            cout<<">Employee ID#"<<it->id<<"  "<<"Name: "<<it->fName<<" "<<it->lName<<endl<<endl;
            it = it->next;
        } while(it->next != NULL);

    }
}

void Employees::dDisplay(){

    if(head == NULL){
        cout<<">No employees to display<"<<endl<<endl;
    }
    else{
        it = head;

        do{
            cout<<">Employee ID#"<<it->id<<"<"<<endl;
            cout<<"Name: "<<it->fName<<" "<<it->lName<<endl;
            cout<<"Street Address: "<<it->sAddress<<endl;
            cout<<"Age: "<<it->age<<endl;
            cout<<"Position: "<<it->position<<endl<<endl;
            it = it->next;
        } while(it->next != NULL);
    }
}




